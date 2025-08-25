class TrieNode {
public:
    bool terminal;
    string word;
    TrieNode* children[26];

    TrieNode(){
        terminal = false;
        word = "";
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie(){ 
        root = new TrieNode(); 
    }
    void insert(const string& word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';
    
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }

        node->terminal = true;
        node->word = word;
    }

    TrieNode* getRoot() const { return root; }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        vector<string> ans;

        Trie trie;
        for (const string& w : words) {
            trie.insert(w);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, trie.getRoot(), ans);
            }
        }

        return ans;
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& ans) {
        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) return;

        char ch = board[i][j];
        if (ch == '#' || !node->children[ch - 'a']) return;

        node = node->children[ch - 'a'];
        if (node->terminal) {
            ans.emplace_back(node->word);
            node->terminal = false; // avoid duplicates
        }

        board[i][j] = '#'; // mark visited

        dfs(board, i + 1, j, node, ans);
        dfs(board, i - 1, j, node, ans);
        dfs(board, i, j + 1, node, ans);
        dfs(board, i, j - 1, node, ans);

        board[i][j] = ch;
    }
};

class Solution {
public:
    vector<string> ans;
    int m, n;

    struct trieNode{
        bool terminal;
        string word;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->terminal = false;
        newNode->word = "";
        for(int i = 0; i < 26; i++){
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    void insert(trieNode* root, string& word){
        trieNode* crawler = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(crawler->children[ch - 'a'] == NULL){
                crawler->children[ch - 'a'] = getNode();
            }

            crawler = crawler->children[ch - 'a'];
        }

        crawler->terminal = true;
        crawler->word = word;
    }

    void findWords(vector<vector<char>>& board, int i, int j, trieNode* root){
        if(i < 0 || i >= m || j < 0 || j >=n) return;

        char ch = board[i][j];

        if(board[i][j] == '#' || root->children[board[i][j] - 'a'] == NULL) return;

        root = root->children[board[i][j] - 'a'];

        if(root->terminal == true){
            ans.push_back(root->word);
            root->terminal = false;
        }
        board[i][j] = '#';

        findWords(board, i + 1, j, root);
        findWords(board, i - 1, j , root);
        findWords(board, i, j + 1, root);
        findWords(board, i, j - 1, root);

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        
        trieNode* root = getNode();

        for(string& s : words){
            insert(root, s);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char ch = board[i][j];
                if(root->children[ch- 'a'] != NULL){
                    findWords(board, i, j, root);
                }

            }
        }

        return ans;
    }
};
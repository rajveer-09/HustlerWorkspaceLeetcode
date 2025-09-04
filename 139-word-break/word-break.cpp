class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isTerminal = true;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        for (const string& word : wordDict) {
            t.insert(word);
        }
        
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 0; i < s.size(); i++) {
            if (dp[i]) {
                TrieNode* node = t.root;
                for (int j = i; j < s.size(); j++) {
                    int index = s[j] - 'a';
                    if (!node->children[index]) {
                        break;
                    }
                    node = node->children[index];
                    if (node->isTerminal) {
                        dp[j + 1] = true;
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};
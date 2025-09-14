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
                        if(dp[s.size()]) return true;
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};
// class Solution {
// public:
//     // bool solve(int idx, string& s, unordered_set<string>& st, vector<int>& dp){
//     //     if(idx == s.size()) return true;
//     //     if(dp[idx] != -1) return dp[idx];

//     //     for(int len = 1; len <= s.size() - idx; len++){
//     //         string part = s.substr(idx, len);
//     //         if(st.count(part) && solve(idx + len, s, st, dp)){
//     //             return dp[idx] = true;
//     //         }
//     //     }
        
//     //     return dp[idx] = false;
//     // }

//     // bool wordBreak(string s, vector<string>& wordDict) {
//     //     unordered_set<string> st(wordDict.begin(), wordDict.end());
//     //     vector<int> dp(s.size(), -1);

//     //     return solve(0, s, st, dp);
//     // }

//     // bool wordBreak(string s, vector<string>& wordDict) {
//     //     // unordered_set -> O(1) average time complexity lookups
//     //     unordered_set<string> dict(wordDict.begin(), wordDict.end());

//     //     int n = s.length();
//     //     vector<bool> dp(n + 1, false);
//     //     dp[0] = true;

//     //     for (int i = 1; i <= n; ++i) {
//     //         for (int j = 0; j < i; ++j) {
//     //             // dp[j] is true, meaning s[0...j-1] can be segmented
//     //             // s.substr(j, i-j) is a word in the dictionary
//     //             if (dp[j] && dict.count(s.substr(j, i - j))) {
//     //                 dp[i] = true;
//     //                 break;
//     //             }
//     //         }
//     //     }

//     //     return dp[n];
//     // }
// };

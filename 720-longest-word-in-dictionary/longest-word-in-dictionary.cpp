class TrieNode{
public:
    bool terminal;
    TrieNode* children[26];

    TrieNode(){
        terminal = false;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};
class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string& s){
        TrieNode* crawler = root;
        for(int i = 0; i < s.size(); i++){
            int idx = s[i] - 'a';
            // info sirf baap rakhega bachcha banatey time
            // bachcha kab banega koi info nahi hoga uske pass
            if(crawler->children[idx] == NULL){
                TrieNode* newNode = new TrieNode();
                crawler->children[idx] = newNode;
            }

            crawler = crawler->children[idx];
        }
        // for loop end hone k baad termnial mark true krenge
        crawler->terminal = true;
    }

    bool checkIfAllPrefixExists(string word){
        TrieNode* crawler = root;

        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(crawler->children[idx] == NULL){
                return false;
            }
            crawler = crawler->children[idx];

            if(!crawler->terminal) return false;
        }

        return true;
    }
};
class Solution {
public:
    string longestWord(vector<string>& nums) {
        Trie* trie = new Trie();

        for(string& s : nums){
            trie->insert(s);
        }

        string longest = ""; 

        for (int i = 0; i < nums.size(); i++) {
            if (trie->checkIfAllPrefixExists(nums[i])) {
                if (nums[i].size() > longest.size()) {
                    longest = nums[i];
                } 
                else if (nums[i].size() == longest.size() && nums[i] < longest) {
                    longest = nums[i];  
                }
            }
        }

        return longest.empty() ? "" : longest;
    }
};
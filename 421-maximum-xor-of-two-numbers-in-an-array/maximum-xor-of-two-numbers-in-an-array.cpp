class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int maxLen = 31;

        for (int num : nums) {
            TrieNode* curr = root;
            for (int i = maxLen; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (!curr->children[bit]) {
                    curr->children[bit] = new TrieNode();
                }
                curr = curr->children[bit];
            }
        }
        
        int maxXor = 0;
        for (int num : nums) {
            TrieNode* curr = root;
            int currXor = 0;
            for (int i = maxLen; i >= 0; --i) {
                int bit = (num >> i) & 1;
                int oppositeBit = 1 - bit;
                
                if (curr->children[oppositeBit]) {
                    currXor |= (1 << i);
                    curr = curr->children[oppositeBit];
                } else {
                    curr = curr->children[bit];
                }
            }
            
            maxXor = max(maxXor, currXor);
        }
        
        return maxXor;
    }
};
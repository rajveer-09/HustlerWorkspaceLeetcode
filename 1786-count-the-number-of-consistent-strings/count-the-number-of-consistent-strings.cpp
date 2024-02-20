class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
    
        for (const string& word : words) {
            bool consistent = true;
            for (char c : word) {
                if (allowed.find(c) == -1) { 
                    consistent = false;
                    break;
                }
            }
            if (consistent) {
                count++;
            }
        }
        return count;
    }
};
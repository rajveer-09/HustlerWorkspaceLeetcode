class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int operations = 0;

        for (int num : nums) {
            int complement = k - num;
            
            if (freq[complement] > 0) {
                operations++;
                freq[complement]--;
            } 
            else {
                freq[num]++;
            }
        }
        
        return operations;
    }
};
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        // Step 1: Precompute pairwise AND results
        unordered_map<int, int> pair_and_count;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int and_result = nums[i] & nums[j];
                pair_and_count[and_result]++;
            }
        }
        
        // Step 2: Count valid triples
        for (int k = 0; k < n; ++k) {
            for (auto& [and_result, freq] : pair_and_count) {
                if ((and_result & nums[k]) == 0) {
                    count += freq;
                }
            }
        }
        
        return count;
    }
};
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumCount;
        int prefixSum = 0;
        int result = 0;
        
        // Initialize the map with prefix sum 0 having one occurrence.
        prefixSumCount[0] = 1;
        
        for (int num : nums) {
            prefixSum += num;
            
            // If there exists a prefix sum that when subtracted from the current prefix sum gives the goal
            if (prefixSumCount.find(prefixSum - goal) != prefixSumCount.end()) {
                result += prefixSumCount[prefixSum - goal];
            }
            
            // Update the frequency of the current prefix sum in the map
            prefixSumCount[prefixSum]++;
        }
        
        return result;
    }
};

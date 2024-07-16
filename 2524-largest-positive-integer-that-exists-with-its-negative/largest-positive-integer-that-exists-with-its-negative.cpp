class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int largest_k = -1;

        for (int num : nums) {
            if (num_set.find(-num) != num_set.end()) {
                largest_k = max(largest_k, abs(num));
            }
        }

        return largest_k != -1 ? largest_k : -1;
    }
};
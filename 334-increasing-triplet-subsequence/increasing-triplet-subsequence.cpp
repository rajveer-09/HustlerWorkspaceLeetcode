class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for (int num : nums) {
            // Find the first element in lis >= num
            auto it = lower_bound(lis.begin(), lis.end(), num);

            if (it == lis.end()) {
                // If num is greater than all elements in lis, append it
                lis.push_back(num);
            } else {
                // Replace the first element >= num
                *it = num;
            }
        }

        return lis.size();
    }
    bool increasingTriplet(vector<int>& nums) {
        int len = lengthOfLIS(nums);

        return len >= 3;
    }
};
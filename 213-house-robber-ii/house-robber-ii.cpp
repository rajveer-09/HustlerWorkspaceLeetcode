class Solution {
public:
    // Linear house robbing function
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int prev2 = 0;
        int prev1 = 0;

        for (int i = 0; i < n; ++i) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    // Main function to handle circular houses
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // Pehla se second-to-last tak rob karo
        vector<int> nums1(nums.begin(), nums.end() - 1);
        int rob1 = robLinear(nums1);

        // Second se last tak rob karo
        vector<int> nums2(nums.begin() + 1, nums.end());
        int rob2 = robLinear(nums2);

        // Dono ka maximum return karo
        return max(rob1, rob2);
    }
};

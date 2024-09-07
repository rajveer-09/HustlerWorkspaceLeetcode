class Solution {
public:
    int largestPerimeter(std::vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 3; i >= 0; --i) {
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int ans = max(nums[0] * nums[1] * nums[n-1], nums[n-1] * nums[n-2] * nums[n-3]);

        return ans;
    }
};

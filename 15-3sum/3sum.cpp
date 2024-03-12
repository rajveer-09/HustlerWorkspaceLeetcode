class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int st = i + 1, ed = n - 1;
            while (st < ed) {
                int sum = nums[st] + nums[ed];
                if (sum == target) {
                    ans.push_back({nums[i], nums[st], nums[ed]});
                    while (st < ed && nums[st] == nums[st + 1]) ++st;
                    while (st < ed && nums[ed] == nums[ed - 1]) --ed;
                    ++st;
                    --ed;
                } else if (sum < target) {
                    ++st;
                } else {
                    --ed;
                }
            }
        }
        return ans;
    }
};
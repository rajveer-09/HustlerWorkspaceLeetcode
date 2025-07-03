class Solution {
public:
    void solve(vector<int>& nums, int idx, int sum, vector<int>& v2, vector<vector<int>>& ans) {
        if(idx >= nums.size()){
            if(sum == 0){
                ans.push_back(v2);
            }
            return;
        }

        // take
        if(sum >= nums[idx]){
            v2.push_back(nums[idx]);
            solve(nums, idx, sum - nums[idx], v2, ans);
            v2.pop_back();
        }

        // not take
        solve(nums, idx + 1, sum, v2, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        
        solve(candidates, 0, target, v, ans);

        return ans;
    }
};
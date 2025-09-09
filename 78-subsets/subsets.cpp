class Solution {
public:
    void rec(vector<int>& nums, int idx, vector<vector<int>>& ans, vector<int>& subset){
        if(idx >= nums.size()){
            ans.push_back(subset);
            return;
        }

        // take
        subset.push_back(nums[idx]);
        rec(nums, idx + 1, ans, subset);
        subset.pop_back();

        // not_take
        rec(nums, idx + 1, ans, subset);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;

        rec(nums, 0, ans, subset);

        return ans;
    }
};

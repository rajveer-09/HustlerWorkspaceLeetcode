class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index) {
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int j = index; j < nums.size(); j++) {
            swap(nums[index], nums[j]);
            solve(nums, ans, index + 1);
            swap(nums[index], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // ensures lexicographical order
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }

};
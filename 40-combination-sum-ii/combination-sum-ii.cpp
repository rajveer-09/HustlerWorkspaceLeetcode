class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(vector<int>& candidates, int idx, int target, vector<int>& tmp) {
        if (idx >= n || target < 0) {
            if (target == 0 && !tmp.empty()) {
                ans.push_back(tmp);
            }
            return;
        }

        // take
        tmp.push_back(candidates[idx]);
        solve(candidates, idx + 1, target - candidates[idx], tmp);
        tmp.pop_back();

        // skip duplicates
        int nxtIdx = idx + 1;
        while (nxtIdx < n && candidates[nxtIdx] == candidates[idx]) nxtIdx++;

        // skip
        solve(candidates, nxtIdx, target, tmp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();

        vector<int> tmp;
        solve(candidates, 0, target, tmp);

        return ans;
    }
};

class Solution {
public:
    void rec(int i, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
        if (i >= arr.size()) {
            if(target == 0) ans.push_back(ds);
            
            return;
        }

        // TAKE
        if (arr[i] <= target) {
            ds.push_back(arr[i]);
            rec(i + 1, target - arr[i], arr, ds, ans);
            ds.pop_back();
        }

        // NOT TAKE: skip all duplicates at same level
        int j = i + 1;

        while (j < arr.size() && arr[j] == arr[i]) j++;

        rec(j, target, arr, ds, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); // sort for duplicates handling

        vector<vector<int>> ans;
        vector<int> ds;

        rec(0, target, arr, ds, ans);

        return ans;
    }
};

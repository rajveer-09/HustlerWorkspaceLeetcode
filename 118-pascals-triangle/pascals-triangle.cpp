class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});

        for(int i = 1; i < numRows; i++){
            vector<int> newRow;
            newRow.push_back(1);

            for(int j = 1; j < ans[i - 1].size(); j++){
                newRow.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }

            newRow.push_back(1);

            ans.push_back(newRow);
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);

        if (n >= 1) ans[0] = {1};       
        if (n >= 2) ans[1] = {1, 1};

        for (int i = 2; i < n; ++i) {
            vector<int> temp(i + 1, 0);
            temp[0] = 1;  
            for (int j = 1; j < i; ++j) {
                temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            temp[i] = 1;
            ans[i] = temp;
        }

        return ans;
    }
};

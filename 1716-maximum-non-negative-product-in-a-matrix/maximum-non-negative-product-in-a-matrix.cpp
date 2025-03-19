class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<long long>> dpMax(n, vector<long long>(m, 0));
        vector<vector<long long>> dpMin(n, vector<long long>(m, 0));
        
        dpMax[0][0] = dpMin[0][0] = grid[0][0];

        for (int j = 1; j < m; j++) {
            dpMax[0][j] = dpMin[0][j] = dpMax[0][j - 1] * grid[0][j];
        }

        for (int i = 1; i < n; i++) {
            dpMax[i][0] = dpMin[i][0] = dpMax[i - 1][0] * grid[i][0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                long long val = grid[i][j];
                long long maxProd = max({dpMax[i - 1][j] * val, dpMin[i - 1][j] * val,
                                         dpMax[i][j - 1] * val, dpMin[i][j - 1] * val});
                                         
                long long minProd = min({dpMax[i - 1][j] * val, dpMin[i - 1][j] * val,
                                         dpMax[i][j - 1] * val, dpMin[i][j - 1] * val});

                dpMax[i][j] = maxProd;
                dpMin[i][j] = minProd;
            }
        }

        return (dpMax[n - 1][m - 1] < 0) ? -1 : (dpMax[n - 1][m - 1] % 1000000007);
    }
};
class Solution {
public:
    int maxRow(vector<vector<int>>& mat, int col) {
        int n = mat.size();
        int maxi_r = 0;

        for (int i = 0; i < n; i++) {
            if (mat[i][col] > mat[maxi_r][col]) {
                maxi_r = i;
            }
        }
        return maxi_r;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        // binary search on columns
        int low = 0, high = m - 1; 

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int maxi_r = maxRow(mat, mid); // row with max in col `mid`

            if (mid - 1 >= 0 && mat[maxi_r][mid - 1] > mat[maxi_r][mid]) {
                high = mid - 1;
            }
            else if (mid + 1 < m && mat[maxi_r][mid + 1] > mat[maxi_r][mid]) {
                low = mid + 1;
            }
            else {
                return {maxi_r, mid};
            }
        }

        return {-1, -1};
    }
};

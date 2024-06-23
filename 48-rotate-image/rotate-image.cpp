class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> temp(n * n, 0);
        int p = 0;

        for (int j = 0; j < n; j++) {
            for (int i = n - 1; i >= 0; i--) {
                temp[p++] = matrix[i][j];
            }
        }

        p = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = temp[p++];
            }
        }
    }
};
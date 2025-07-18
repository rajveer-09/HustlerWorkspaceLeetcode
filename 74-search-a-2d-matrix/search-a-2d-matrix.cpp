class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int st = 0, ed = m * n - 1;

        while (st <= ed) {
            int mid = st + (ed - st) / 2;
            int val = matrix[mid / m][mid % m];

            if (val > target) {
                ed = mid - 1;
            } 
            else if (val < target) {
                st = mid + 1;
            } 
            else {
                return true;
            }
        }

        return false;
    }
};
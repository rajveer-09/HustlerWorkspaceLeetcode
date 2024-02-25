class Solution {
public:
    pair<int, int> find_pos(int k, int n) {
        pair<int, int> z;
        z.first = k / n;
        z.second = k % n;

        return z;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l  = -1, r = n * m;

        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            int x = mid / n, y = mid % n;

            if(matrix[x][y] == target) {
                return true;
            }
            
            if(matrix[x][y] > target) {
                r = mid;
            }

            else {
                l = mid;
            }

        }

        return false; 
    }
};
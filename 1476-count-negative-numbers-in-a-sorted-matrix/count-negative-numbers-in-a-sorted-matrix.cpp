class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                count += m - row; // All elements below grid[row][col] in the current column are negative
                col--; // Move left in the same row
            } 
            else {
                row++; // Move down to the next row
            }
        }

        return count;
    }
};
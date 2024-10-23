class Solution {
    public boolean satisfiesConditions(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Check condition with the cell below
                if (i < m - 1 && grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
                // Check condition with the cell to the right
                if (j < n - 1 && grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
        }
        
        return true;
    }
}

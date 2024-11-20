class Solution {
    public boolean dfs(int i, int j, int[][] grid1, int[][] grid2, boolean[][] vis) {
        int n = grid1.length;
        int m = grid1[0].length;

        // Boundary conditions and already visited cell check
        if (i < 0 || i >= n || j < 0 || j >= m || grid2[i][j] != 1 || vis[i][j]) {
            return true;
        }

        vis[i][j] = true;

        // Check if current cell in grid2 matches the cell in grid1
        boolean isSubIsland = (grid1[i][j] == grid2[i][j]);

        // Continue DFS in all four directions
        boolean up = dfs(i - 1, j, grid1, grid2, vis);
        boolean down = dfs(i + 1, j, grid1, grid2, vis);
        boolean left = dfs(i, j - 1, grid1, grid2, vis);
        boolean right = dfs(i, j + 1, grid1, grid2, vis);

        // Return true if all parts of the island in grid2 match the corresponding parts in grid1
        return isSubIsland && up && down && left && right;
    }

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int n = grid1.length;
        int m = grid1[0].length;

        boolean[][] vis = new boolean[n][m];
        int count = 0;

        // Iterate through all cells in grid2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Start DFS if the cell in grid2 is part of an island and not yet visited
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    if (dfs(i, j, grid1, grid2, vis)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
}

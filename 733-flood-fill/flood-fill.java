class Solution {
    public void bfs(int[][] grid, int i, int j, int newColor, boolean[][] visited) {
        int n = grid.length;
        int m = grid[0].length;

        int val = grid[i][j];

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{i, j});

        visited[i][j] = true;
        grid[i][j] = newColor;

        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.isEmpty()) {
            int[] pos = q.poll();
            int x = pos[0];
            int y = pos[1];

            for (int[] dir : directions) {
                int xx = x + dir[0];
                int yy = y + dir[1];

                if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                    if (!visited[xx][yy] && grid[xx][yy] == val) {
                        q.offer(new int[]{xx, yy});
                        visited[xx][yy] = true;
                        grid[xx][yy] = newColor;
                    }
                }
            }
        }
    }

    public int[][] floodFill(int[][] grid, int sr, int sc, int newColor) {
        int n = grid.length;
        int m = grid[0].length;

        boolean[][] visited = new boolean[n][m];

        bfs(grid, sr, sc, newColor, visited);

        return grid;
    }
}
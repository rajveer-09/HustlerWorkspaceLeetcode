class Solution {
    public void dfs(char[][] grid, int i, int j, boolean[][] vis) {
        int m = grid.length;
        int n = grid[0].length;

        if (i < 0 || j < 0 || i >= m || j >= n) return;

        if (grid[i][j] != '1' || vis[i][j]) return;

        vis[i][j] = true;

        dfs(grid, i - 1, j, vis);
        dfs(grid, i + 1, j, vis);
        dfs(grid, i, j - 1, vis);
        dfs(grid, i, j + 1, vis);

    }
    public void bfs(char[][] grid, int i, int j, boolean vis[][]){
        int n = grid.length;
        int m = grid[0].length;

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{i, j});

        vis[i][j] = true;

        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        while(!q.isEmpty()){
            int[] node = q.poll();
            int x = node[0];
            int y = node[1];

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(nx >= 0 && nx < n  && ny >= 0 && ny < m){
                    if(grid[nx][ny] == '1' && !vis[nx][ny]){
                        q.add(new int[]{nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            
        }

    }
    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        boolean vis[][] = new boolean [n][m];
        int cnt = 0;


        for(int i = 0; i < n; i++){
            for(int j = 0; j <  m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid, i, j, vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
}
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& a, vector<vector<bool>>& visited, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || a[i][j] == 'X' || visited[i][j]) {
            return;
        }

        visited[i][j] = true;

        // Recursive DFS calls for adjacent cells
        dfs(i - 1, j, a, visited, n, m);
        dfs(i + 1, j, a, visited, n, m);
        dfs(i, j - 1, a, visited, n, m);
        dfs(i, j + 1, a, visited, n, m);
    }

    void solve(vector<vector<char>>& a) {
        int n = a.size();
        if (n == 0) return;
        int m = a[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Mark border connected 'O's
        for (int i = 0; i < n; i++) {
            if (a[i][0] == 'O') dfs(i, 0, a, visited, n, m);
            if (a[i][m - 1] == 'O') dfs(i, m - 1, a, visited, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (a[0][j] == 'O') dfs(0, j, a, visited, n, m);
            if (a[n - 1][j] == 'O') dfs(n - 1, j, a, visited, n, m);
        }

        // Flip surrounded 'O's to 'X's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'O' && !visited[i][j]) {
                    a[i][j] = 'X';
                }
            }
        }
    }
};

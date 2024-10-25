class Solution{
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& mat, int i, int j, vector<vector<bool>>& visited){
        int n = mat.size();
        int m = mat[0].size();

        visited[i][j] = true;

        for(auto dir : dirs){
            int x = i + dir.first;
            int y = j + dir.second;

            if(x >=0 && x < n && y >= 0 && y < m){
                if(!visited[x][y] && mat[x][y] == 'O'){
                    dfs(mat, x, y, visited);
                }
            }
        }

    }
    void solve(vector<vector<char>>& mat) {
       int n = mat.size();
       int m = mat[0].size();

       vector<vector<bool>> visited(n, vector<bool>(m, false));

       for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            if(i == 0 || i == n-1 || j == 0 || j == m -1){
                if(!visited[i][j] && mat[i][j] == 'O'){
                    dfs(mat, i, j, visited);
                }
            }
        }
       }

       for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 'O' && visited[i][j]){

            }
            else mat[i][j] = 'X';
        }
       }
    }
};
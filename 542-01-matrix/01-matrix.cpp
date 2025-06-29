class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();

            for(auto d : dir){
                int xx = x + d[0];
                int yy = y + d[1];

                if(xx >= 0 && xx < n && yy >= 0 && yy < m && dist[xx][yy] == -1){
                    dist[xx][yy] = dist[x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }

        return dist;
    }
};

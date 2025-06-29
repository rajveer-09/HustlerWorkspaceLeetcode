class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        int cnt = 0;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            int sz = q.size();
            bool changed = false;

            for(int i = 0; i < sz; i++){
                auto [x, y] = q.front(); q.pop();

                for(auto& d : dir){
                    int xx = x + d[0];
                    int yy = y + d[1];

                    if(xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == 1){
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                        changed = true;
                    }
                }
            }

            if(changed) cnt++;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return cnt;
    }
};
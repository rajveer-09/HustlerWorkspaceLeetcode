class Solution{
public:
    int numIslands(vector<vector<char>> &grid){
        int cnt = 0;

        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));

        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(grid, i, j, visited);
                }
            }
        }

        return cnt;
    }
private:
    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        q.push({i, j});
        visited[i][j] = true;

        while(!q.empty()){
            auto p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();

            vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for(auto it : dir){
                int xx = x + it.first;
                int yy = y + it.second;

                if(xx >= 0 && xx < n && yy >= 0 && yy < m){
                    if(!visited[xx][yy] && grid[xx][yy] == '1'){
                        q.push({xx, yy});
                        visited[xx][yy] = true;
                    }
                }
            }
        }
    }
};

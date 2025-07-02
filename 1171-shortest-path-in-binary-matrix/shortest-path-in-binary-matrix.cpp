class Solution {
public:
    typedef pair<int, pair<int, int>> P; // dist, {i, j}
    int n,m;
    bool isValid(int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        if(grid[0][0] != 0 || grid[n - 1][m - 1] != 0) return -1;

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        vector<int> dirX = {-1, 0, 1};
        vector<int> dirY = {-1, 0, 1};

        pq.push({1, {0, 0}});
        dist[0][0] = 1;

        while(!pq.empty()){
            int d = pq.top().first;
            int xx = pq.top().second.first;
            int yy = pq.top().second.second;

            pq.pop();

            for(auto dx : dirX){
                for(auto dy : dirY){
                    int x = dx + xx;
                    int y = dy + yy;

                    if(isValid(x, y) && grid[x][y] == 0){
                        if(dist[x][y] > d + 1){
                            dist[x][y] = d + 1;
                            pq.push({d + 1, {x, y}});
                        }
                    }
                }
            }
        }

        if(dist[n - 1][m - 1] == 1e9) return -1;

        return dist[n - 1][m - 1];

        
    }
};
class Solution {
public:
    void eat(vector<vector<char>> &grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != '1') return;
        grid[i][j] = '0';
        eat(grid,i+1,j);
        eat(grid,i,j+1);
        eat(grid,i-1,j);
        eat(grid,i,j-1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    eat(grid,i,j);
                }
            }
        }
        return ans;
    }
};
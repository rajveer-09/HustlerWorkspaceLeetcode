class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < n; ++i){

            if(i > 0 && grid[0][i] == grid[0][i - 1]) return false;

            for(int j = 1; j < m; ++j){
                if(grid[j][i] != grid[j - 1][i]) return false;
            }
        }

        return true;
    }
};
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int c = grid[0].size();
        vector<long long> pre(c, 0);
        vector<long long> suff(c, 0);
        
        pre[0] = grid[1][0];
        for (int i = 1; i < c; ++i) {
            pre[i] = pre[i - 1] + grid[1][i];
        }
        

        suff[c - 1] = grid[0][c - 1];
        for (int i = c - 2; i >= 0; --i) {
            suff[i] = suff[i + 1] + grid[0][i];
        }
        
        long long mini = LLONG_MAX;
        
        for (int i = 0; i < c; ++i) {
            long long x = (i < c - 1) ? suff[i + 1] : 0;
            long long y = (i > 0) ? pre[i - 1] : 0;
            
            mini = min({mini, max(x , y)});
        }
        
        return mini;
    }
};
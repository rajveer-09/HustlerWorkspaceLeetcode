class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        ios_base::sync_with_stdio(false);
        int size = ops.size();
        for(int i=0;i<size;i++){
            if(m>ops[i][0]){
                m = ops[i][0];
            }
            if(n>ops[i][1]){
                n = ops[i][1];
            }
        }
        return m*n;
    }
};
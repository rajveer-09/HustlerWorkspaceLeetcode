class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size(), ans = 0;
        for (int i=0; i<n; i++) {
            #pragma unroll
            for (int j=1; j<m; j++) {
                if (strs[j][i] < strs[j-1][i]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

auto boom = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
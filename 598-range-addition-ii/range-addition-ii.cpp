class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int opsLen = ops.size();

        if (opsLen == 0) return m * n;
        int miR = m, miC = n;
        for (int i = 0; i < opsLen; i++) {
            miR = min(miR, ops[i][0]);
            miC = min(miC, ops[i][1]);
        }

        return miR * miC;
    }
};
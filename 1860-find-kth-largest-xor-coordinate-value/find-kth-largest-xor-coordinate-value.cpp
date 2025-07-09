class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        vector<vector<int>> xorValues(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                xorValues[i][j] = matrix[i][j];
                if (i > 0) xorValues[i][j] ^= xorValues[i-1][j];
                if (j > 0) xorValues[i][j] ^= xorValues[i][j-1];

                if (i > 0 && j > 0) xorValues[i][j] ^= xorValues[i-1][j-1];
                
                pq.push(xorValues[i][j]);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        
        return pq.top();
    }
};
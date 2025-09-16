class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

/*

<-- BRUTE FORCE -->
1. COLUMN num is becoming new row number
2. ith row is going to m - 1 - i th column

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int>(n, 0)); 
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }
        
        for(int i = 0; i < rotated.size(); i++){
            for(int j = 0; j < rotated[0].size(); j++){
                matrix[i][j] = rotated[i][j];
            }
        }
    }
};


*/
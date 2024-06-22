#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> indi;
        unordered_set<int> indj;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    indi.insert(i);
                    indj.insert(j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (indi.count(i) || indj.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> diag;  // key: i + j
        int total = 0;

        // Step 1: Group elements by (i + j)
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                diag[i + j].push_back(nums[i][j]);
                total++;
            }
        }

        // Step 2: Collect result from grouped diagonals
        vector<int> res;
        for (auto& [key, vec] : diag) {
            // Insert elements from back to front because top rows come first
            for (int i = vec.size() - 1; i >= 0; --i)
                res.push_back(vec[i]);
        }

        return res;
    }
};

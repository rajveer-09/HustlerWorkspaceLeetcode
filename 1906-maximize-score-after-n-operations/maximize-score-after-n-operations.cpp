class Solution {
public:
    // Main function to compute the maximum score
    int maxScore(vector<int>& nums) {
        int m = nums.size();  // Total number of elements
        int n = m / 2;        // Number of operations to perform (half the array length)
        
        // Initialize DP vector to store results for each subset
        vector<int> dp(1 << m, -1);
        
        // 2D vector to store GCD of each pair of elements
        vector<vector<int>> gcd(m, vector<int>(m));
        
        // Compute GCD for each pair of elements
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                gcd[i][j] = gcdFunction(nums[i], nums[j]);
            }
        }
        
        // Start recursive computation
        return rec(nums, 1, 0, dp, m, n, gcd);
    }

private:
    // Recursive function to calculate the maximum score
    int rec(const vector<int>& nums, int op, int mask, vector<int>& dp, int m, int n, const vector<vector<int>>& gcd) {
        if (op > n) return 0;  // Base case: if all operations are done
        
        if (dp[mask] != -1) return dp[mask];  // Return cached result if available
        
        int maxScore = 0;  // Variable to track the maximum score
        
        // Iterate over all pairs of elements
        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) continue;  // Skip if element i is already selected
            
            for (int j = i + 1; j < m; ++j) {
                if (mask & (1 << j)) continue;  // Skip if element j is already selected
                
                // Create a new mask by selecting elements i and j
                int newMask = mask | (1 << i) | (1 << j);
                
                // Calculate the score for the current pair
                int score = op * gcd[i][j] + rec(nums, op + 1, newMask, dp, m, n, gcd);
                
                // Update the maximum score
                maxScore = max(maxScore, score);
            }
        }
        
        // Cache the result and return it
        return dp[mask] = maxScore;
    }
    
    // Function to compute the GCD of two numbers
    int gcdFunction(int a, int b) {
        return b == 0 ? a : gcdFunction(b, a % b);
    }
};

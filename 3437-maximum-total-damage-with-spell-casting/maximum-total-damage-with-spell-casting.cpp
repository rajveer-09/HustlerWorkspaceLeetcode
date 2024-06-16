class Solution {
private:
    long long dpHelp(vector<int>& power, unordered_map<int, long long>& count, int idx, vector<long long>& dp) {
        if (idx < 0) return 0;
        if (dp[idx] != -1) return dp[idx];
        
        long long notPick = dpHelp(power, count, idx - 1, dp);  // Maximum damage without picking the current index
        
        long long pick = power[idx] * count[power[idx]];  // Maximum damage by picking the current index
        
        // Check conditions for picking previous powers
        if (idx >= 1 && power[idx] == power[idx - 1] + 1) {
            // If current power is consecutive to the previous one, decide to skip one or two indices back
            if (idx >= 2 && power[idx] == power[idx - 2] + 2) {
                pick += dpHelp(power, count, idx - 3, dp);  // Skip two indices back
            } else {
                pick += dpHelp(power, count, idx - 2, dp);  // Skip one index back
            }
        } else {
            // Otherwise, skip one index back
            if (idx > 0 && power[idx] == power[idx - 1] + 2) {
                pick += dpHelp(power, count, idx - 2, dp);  // Skip one index back
            } else {
                pick += dpHelp(power, count, idx - 1, dp);  // Do not skip
            }
        }
        
        // Store and return the maximum of picking or not picking the current index
        return dp[idx] = max(pick, notPick);
    }
    
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> count;
        
        // Count frequencies of each power
        for (auto it : power) {
            count[it]++;
        }
        
        // Extract unique powers and sort them
        vector<int> p;
        for (auto it : count) {
            p.push_back(it.first);
        }
        sort(p.begin(), p.end());
        
        // Initialize dp array with -1
        int n = p.size();
        vector<long long> dp(n, -1);
        
        // Call the dpHelp function with the sorted unique powers
        return dpHelp(p, count, n - 1, dp);
    }
};
class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> dp;

    int ways(int n) {
        if (n == 0) return 1;
        if (n == 1) return 2;
        if (dp[n] != -1) return dp[n];

        return dp[n] = (ways(n - 1) + ways(n - 2)) % MOD;
    }

    int countHousePlacements(int n) {
        dp.assign(n + 1, -1);
        long long oneSide = ways(n);
        
        return (oneSide * oneSide) % MOD;
    }
};
/*
=> If the last plot is empty (E) → then the first n-1 plots can be arranged in ways(n-1) ways.
=> If the last plot is house (H) → then the (n-1)th plot must be empty.
So we fix E at (n-1) and H at n.
The first n-2 plots can be arranged in ways(n-2) ways.
*/
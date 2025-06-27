class Solution {
public:
    long long dp[100005];

    long long dfs(int i, vector<int>& values, unordered_map<int, long long>& damageMap) {
        if (i >= values.size()) return 0;
        if (dp[i] != -1) return dp[i];

        // Option 1: skip this value
        long long notPick = dfs(i + 1, values, damageMap);

        // Option 2: pick this value and skip all values from values[i]+1 to values[i]+2
        long long pick = damageMap[values[i]];
        int nextIndex = i + 1;
        while (nextIndex < values.size() && values[nextIndex] <= values[i] + 2) nextIndex++;

        pick += dfs(nextIndex, values, damageMap);

        return dp[i] = max(pick, notPick);
    }

    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> damageMap;
        for (int dmg : power)  damageMap[dmg] += dmg;

        vector<int> values;
        for (auto& [val, sum] : damageMap) values.push_back(val);

        sort(values.begin(), values.end());
        memset(dp, -1, sizeof(dp));

        return dfs(0, values, damageMap);
    }
};

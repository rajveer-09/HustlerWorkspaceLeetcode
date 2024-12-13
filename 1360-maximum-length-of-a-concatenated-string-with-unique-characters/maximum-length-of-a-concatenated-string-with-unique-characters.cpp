class Solution {
public:
    bool hasDupli(string& s1, string& s2) {
        int arr[26] = {0};
        for (char& ch : s1) {
            if (arr[ch - 'a'] != 0) return true;
            arr[ch - 'a']++;
        }

        for (char& ch : s2) {
            if (arr[ch - 'a'] != 0) return true;
        }

        return false;
    }

    unordered_map<string, int> dp;

    int memo(vector<string>& arr, int n, int idx, string ans) {
        if (idx >= n) return ans.size();

        if (dp.find(ans) != dp.end()) return dp[ans];

        int inc = 0;
        int exc = 0;

        if (hasDupli(arr[idx], ans)) {
            exc = memo(arr, n, idx + 1, ans);
        } else {
            inc = memo(arr, n, idx + 1, ans + arr[idx]);
            exc = memo(arr, n, idx + 1, ans);
        }

        return dp[ans] = max(inc, exc);
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        dp.clear();

        return memo(arr, n, 0, "");
    }
};
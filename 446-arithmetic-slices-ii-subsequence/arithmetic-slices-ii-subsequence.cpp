class Solution {
private:
    unordered_map<string, int> dp;
    int solve(vector<int>& nums, int start, int curr, int len, long diff) {
        if (curr == nums.size() - 1)
            return 0;

        string temp = to_string(curr) + "#" + to_string(len);
        if (dp.find(temp) != dp.end()) return dp[temp];

        int res = 0;
        for (int i = curr + 1; i < nums.size(); i++) {
            long k = static_cast<long>(nums[i]) - static_cast<long>(nums[curr]);
            if (len == 1 || diff == k) {
                len += 1;
                if (len >= 3) res++;
                res += solve(nums, start, i, len, k);
                len -= 1;
            }
        }

        return dp[temp] = res;;
    }
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp.clear();
            res += solve(nums, i, i, 1, 0);
        }
        return res;
    }
};
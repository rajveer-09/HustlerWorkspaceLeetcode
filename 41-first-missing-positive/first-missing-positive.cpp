class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int n = nums.size();
        vector<int> mp(n + 1, 0);

        for (int num : nums) {
            if (num > 0 && num <= n) {
                mp[num] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (mp[i] == 0) {
                return i;
            }
        }

        return n + 1;
    }
};
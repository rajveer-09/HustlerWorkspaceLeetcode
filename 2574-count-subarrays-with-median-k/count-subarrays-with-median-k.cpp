class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        int n = nums.size(), s = 0, ans = 0;
        bool flg = false;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] > k) {
                ++s;
            } 
            else if (nums[i] < k) {
                --s;
            } 
            else {
                flg = true;
            }

            if (!flg) {
                ++mp[s];
            } 
            else {
                if (mp.find(s) != mp.end()) {
                    ans += mp[s];
                }
                if (mp.find(s - 1) != mp.end()) {
                    ans += mp[s - 1];
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 2 * k + 1;
        vector<int> ans(n, -1);
        if (n < len) return ans;

        long long sum = 0;
        int st = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            
            if (i - st + 1 == len) {
                ans[i - k] = sum / len;
                sum -= nums[st];
                st++;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        
        int ans = INT_MIN;

        int csum = 0;

        for (int i = 0; i < nums.size(); i++) {
            csum += nums[i];

            ans = max(csum, ans);

            if (csum < 0)
                csum = 0;
        }

        return ans;
    }
};
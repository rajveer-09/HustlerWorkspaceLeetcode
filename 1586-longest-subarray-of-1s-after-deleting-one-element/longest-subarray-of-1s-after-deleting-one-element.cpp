class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int st = 0;
        int zeroCount = 0;
        int ans = 0;

        for (int ed = 0; ed < nums.size(); ed++) {
            if (nums[ed] == 0) {
                zeroCount++;
            }

            while (zeroCount > 1) {
                if (nums[st] == 0) {
                    zeroCount--;
                }
                st++;
            }

            ans = max(ans, ed - st);
        }

        return ans;
    }
};

class Solution {
public:
    /* __DP SOLUTION__
    Track maximum product ending at index i.
    But negatives flip the sign → also need minimum product ending at i. 
    */
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = 1, curMax = 1;

        for (int num : nums) {
            int tmp = curMax * num;

            curMax = max(max(num * curMax, num * curMin), num);
            curMin = min(min(tmp, num * curMin), num);

            res = max(res, curMax);
        }

        return res;
    }
};
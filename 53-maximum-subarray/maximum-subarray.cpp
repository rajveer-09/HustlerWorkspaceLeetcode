class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mxsum = INT_MIN;
        int temp = 0;

        for (int i = 0; i < n; ++i) {
            temp += nums[i];

            if (temp > mxsum)  mxsum = temp;
            if (temp < 0) temp =0;
        }
        return mxsum;
    }
};

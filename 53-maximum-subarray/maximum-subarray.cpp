class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int cSum = 0;

        for(int i = 0; i < nums.size(); i++){
            cSum = max(cSum + nums[i], nums[i]);
            maxSum = max(cSum, maxSum);
        }

        return maxSum;
    }
};
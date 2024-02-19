class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int c_sum = 0;
        int max_sum = nums[0];
        for(int i = 0; i <n; i++) {
            c_sum += nums[i];
            if(c_sum > max_sum) max_sum = c_sum;
            if(c_sum < 0) c_sum = 0;
        }
        return max_sum;
    }
};
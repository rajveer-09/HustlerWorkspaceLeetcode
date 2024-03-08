class Solution {
    public int maxSubArray(int[] nums) {
        if (nums.length == 0) return 0;
        
        int csum = 0;
        int lsum = nums[0];
        int maxNegative = Integer.MIN_VALUE;
        
        for (int i = 0; i < nums.length; i++) {
            csum += nums[i];
            if (csum > lsum) lsum = csum;
            if (csum < 0) {
                csum = 0;
            } else if (nums[i] < 0 && nums[i] > maxNegative) {
                maxNegative = nums[i];
            }
        }
        
        if (lsum == 0 && maxNegative != Integer.MIN_VALUE) return maxNegative;
        
        return lsum;
    }
}

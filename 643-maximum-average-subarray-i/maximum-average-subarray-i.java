class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int st = 0;
        double ans = Integer.MIN_VALUE;
        double sum = 0;
        for(int i = 0; i<nums.length; i++) {
            sum += nums[i];
            if(i-st + 1 == k) {
                ans  = Math.max(ans, sum * 1.0 / k);
                sum -= nums[st];
                st++;
            }
        }
        return ans;
    }
}
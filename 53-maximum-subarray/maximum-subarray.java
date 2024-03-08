class Solution {
    public int maxSubArray(int[] nums) {
        int lsum = nums[0];
        int csum = nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            if(nums[i]>csum+nums[i]) csum=nums[i];
            else csum = csum+nums[i];
            
            if(csum>lsum) lsum=csum;
        }
        
        return lsum;
    }
}
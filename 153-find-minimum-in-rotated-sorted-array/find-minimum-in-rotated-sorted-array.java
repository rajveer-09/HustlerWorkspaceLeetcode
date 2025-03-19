class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        int ans  = Integer.MAX_VALUE;

        while(l <= r){
            int mid = l + ( r- l) / 2;

            if(nums[l] <= nums[mid]){
                ans = Math.min(nums[l], ans);
                l = mid + 1;
            }
            else{
                ans =Math.min(ans, nums[mid]);
                r = mid - 1;
            }
        }

        return ans;
    }
}
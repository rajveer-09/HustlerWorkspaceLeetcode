class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = new int[2];
        ans[0] = -1;
        ans[1] = -1;

        int l = 0, r = nums.length - 1;

        while(l <= r){
            int m = l + (r - l) / 2;

            if(nums[m] == target){
                ans[0] = m;
                r = m - 1;
            }
            else if(nums[m] > target){
                r = m  - 1;
            }
            else{
                l = m + 1;
            }
        }

        l = 0; r = nums.length - 1;
        
        while(l <= r){
            int m = l + (r - l) / 2;

            if(nums[m] == target){
                ans[1] = m;
                l = m + 1;
            }
            else if(nums[m] > target){
                r = m  - 1;
            }
            else{
                l = m + 1;
            }
        }

        return ans;
    }
}
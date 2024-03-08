class Solution {
    public boolean check(int[] nums) {
        boolean rotated = false;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1]) {
                if (rotated) {
                    return false;
                }
                rotated = true;
            }
        }
        if (rotated) {
            return nums[nums.length - 1] <= nums[0];
        }
        return true;
    }
}


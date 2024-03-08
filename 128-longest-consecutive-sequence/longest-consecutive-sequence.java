class Solution {
    public int longestConsecutive(int[] nums) {
        Arrays.sort(nums);
        if(nums.length==0) return 0;
        int ls=1;
        int cs=1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]-nums[i-1]==1) cs++;
            else if(nums[i]==nums[i-1]) continue;
            else cs=1;
            if(cs>ls) ls=cs;
        }
        return ls;
    }
}
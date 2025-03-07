class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        long sum = 0;
        long ans  =0 ;
        int st = 0;
        HashMap <Integer,Integer> mpp = new HashMap<>();
        for (int i = 0; i< nums.length; i++) {
            mpp.put(nums[i] , mpp.getOrDefault(nums[i] , 0) +1);
            sum += nums[i];
            while(mpp.get(nums[i]) > 1) {
                mpp.put(nums[st], mpp.get(nums[st]) -1);
                sum -= nums[st];
                if (mpp.get(nums[st]) == 0) {
                    mpp.remove(nums[st]);
                }
                st++;
            }
            if(i-st+1 == k ) {
                if(mpp.size() == k) ans = Math.max(sum,ans);
                
                mpp.put(nums[st], mpp.get(nums[st]) -1);
                sum -=nums[st];

                if (mpp.get(nums[st]) == 0) {
                    mpp.remove(nums[st]);
                }
                st++;
            }
        }
        return ans;
    }
}
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int n=nums.size();
        int prev=nums[0],pos=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=prev){
                ans+= (long long)(i-pos)*prev;
                prev=nums[i];
                pos=i;
            }
        }
        if(pos!=n-1){
            ans+=(long long)(n-1-pos)*prev;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        /* see ham do pointers se agr fill kre aur ek se Traverse to issue is ki...
        our filling pointer se going ahead of iterating one..which is changing upcoming
        values to tarverse.
        Alt -> have filling vector separate to fill ans
        */
        int n = nums.size();
        vector<int> ans(n, 0);
        int pos = 0, neg = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos += 2;
            }
            else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;

    }
};
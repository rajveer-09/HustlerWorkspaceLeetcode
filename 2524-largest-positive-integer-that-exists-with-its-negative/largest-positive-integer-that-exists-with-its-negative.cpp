class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int>ans(2001,0);
        int result = -1;

        for(int i=0;i<nums.size();i++){
            
            if(ans[-nums[i]+1000]==1){
                if(abs(nums[i])>=result){
                    result = abs(nums[i]);
                }
            }
            
            ans[nums[i]+1000] = 1;
        }

        return result;

    }
};
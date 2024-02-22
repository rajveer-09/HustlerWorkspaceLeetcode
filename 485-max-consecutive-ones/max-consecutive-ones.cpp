class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ctn = 0;
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=1){
                ans = max(ans, ctn);
                ctn = 0;
            }
            else
                ctn++;
        }
        ans = max(ans, ctn);
        return ans;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 2;
        int maxi = 2;

        for(int i = 2; i < nums.size(); i++){
            if(nums[i] == nums[i - 1] + nums[i - 2]){
                cnt++;
            }
            else{
                cnt = 2;
            }

            maxi = max(cnt, maxi);
        }

        return maxi;
    }
};
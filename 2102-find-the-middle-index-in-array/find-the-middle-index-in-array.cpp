class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int sum1=0;
        for(int i=0;i<nums.size();i++){
            sum-=nums[i];

            if(sum1==sum) return i;
            
            sum1+=nums[i];
        }

        return -1;
    }
};
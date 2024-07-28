class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=10e5+1;
        
        for(int i=0;i<nums.size();i++){
            int csum=nums[i];
            
            if(nums[i]>=target) return 1;
            if(i==(nums.size()-1)) break;
            for(int j=i+1;j<nums.size();j++){
                
                csum+=nums[j];
                if(csum>=target){
                    ans=min(ans, j-i+1);
                    break;
                }
            }

            if(csum<target) break;
        }
        if(ans==10e5+1) return 0;

        return ans;
    }
};
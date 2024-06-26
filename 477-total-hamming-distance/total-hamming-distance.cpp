class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                cnt+= __builtin_popcount(nums[i]^nums[j]);
            }
        }

        return cnt;
    }
};
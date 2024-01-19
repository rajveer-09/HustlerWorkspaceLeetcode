class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());
        
        int cnt = 0;

        int i = 0 , j = nums.size()-1;

        while(i<j){
            int val = nums[i]+nums[j];
            if(val < target){
                cnt += j-i;
                i++;
            }
            else if(val >= target){
                j--;
            }
            else i++;
        }
        
        
        
        return cnt;
    }
};
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
       int n = nums.size();
        int i = 0;
        int j=i+1;
        while(i<n && j<n){
            if((nums[i]&1) ==0) i+=2;
            if((nums[j]&1) !=0) j+=2;
            else{
                swap(nums[i],nums[j]);
            }
        }
        return nums;
        
    }
};
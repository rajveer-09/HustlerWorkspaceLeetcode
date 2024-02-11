class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        while(j<n){
            while(nums[i]!=0 && i<n-1) i++;
            if(i>j) j=i;
            if(nums[j]!=0){
                swap(nums[i++],nums[j]);
            }
            j++;
        }
    }
};
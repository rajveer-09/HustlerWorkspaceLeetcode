class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0,current=0,end=nums.size()-1;

        while(current<=end){
            if(nums[current]==0){
                swap(nums[current],nums[start++]);
                if(start>current) current++;
            }
            else if(nums[current]==1) current++;

            else swap(nums[current],nums[end--]);
        }
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;

        while(j < nums.size()){
            // i just have to find non zeroes and put them in order from the start.

            if(nums[j] != 0){
                swap(nums[i], nums[j]);
                i++;
            }

            j++;
        }
    }
};
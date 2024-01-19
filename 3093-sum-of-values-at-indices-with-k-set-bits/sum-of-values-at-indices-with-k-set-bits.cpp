class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
        int sum=0;

        for(int i=0;i<nums.size();i++){
            int count=0;
            int temp = i;

        while (temp) {
            if (temp & 1) {
                count++;
            }
            temp >>= 1; // Right shift by 1 to move to the next bit
            }
            if(count==k){
                sum+=nums[i];
            }
        }
        return sum;
    }
};
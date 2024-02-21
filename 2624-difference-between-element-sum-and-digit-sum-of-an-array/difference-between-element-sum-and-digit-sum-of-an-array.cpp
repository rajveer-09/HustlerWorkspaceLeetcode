class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int tsum = accumulate(nums.begin(),nums.end(),0);

        int digitSum = 0;

        for(auto x : nums){
            while(x){
                int rem = x % 10;
                digitSum+= rem;
                x = x/10;
            }
        }

        return abs(tsum - digitSum);
    }
};
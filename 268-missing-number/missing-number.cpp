class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int sum = 0;
        int n= nums.size();

        for(auto &it : nums){
            sum+= it;
        }

        int nSum = n*(n+1)/2;

        return nSum-sum;
    }
};
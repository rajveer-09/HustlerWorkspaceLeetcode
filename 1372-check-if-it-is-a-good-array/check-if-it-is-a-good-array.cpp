class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
    
        int g = nums[0];
        
        for(int i = 1 ; i<nums.size(); i++){
            g = gcd(g, nums[i]);
            if(g==1) return true;
        }

        return g == 1 ? true : false;
    }
};
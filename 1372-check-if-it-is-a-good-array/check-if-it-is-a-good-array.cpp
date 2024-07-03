class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0;
        for(auto &i: nums){
            g = __gcd(i,g);
            if(g==1)return true;
        }
        return false;
    }
};
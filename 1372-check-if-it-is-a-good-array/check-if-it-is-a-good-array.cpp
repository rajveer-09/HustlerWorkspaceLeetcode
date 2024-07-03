class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int g = 0;
        for(auto &i: nums){
            g = __gcd(i,g);
            if(g==1)return true;
        }
        return false;
    }
};
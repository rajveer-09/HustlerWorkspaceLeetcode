class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1, r = n;
        long long res = 0;
        while(l <= r){
            long long  m = l + ((r - l) / 2);
            long long coins = (m * (m + 1)) / 2;
            if(coins > n){
                r = m - 1;
            }
            else {
                l = m + 1;
                res = max(res, m);
            }
        }
        return res;
    }
};
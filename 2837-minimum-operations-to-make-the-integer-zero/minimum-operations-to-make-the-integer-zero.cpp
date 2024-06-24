#define ll long long
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        //num1 = k*num2 + (2^i1 + 2^i2 + .... + 2^1k)
        //num1 - k*num2 = (2^i1 + 2^i2 + .... + 2^1k)
        for(ll i = 0 ; i <= 60 ; i++){
            ll required = num1 - i*num2;
            ll setbit = __builtin_popcountll(required);
            if(setbit <= i && i <= required) return i;
        }
        return -1;
    }
};
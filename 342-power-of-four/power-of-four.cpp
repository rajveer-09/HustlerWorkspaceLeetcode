class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n < 4) return false;
        return n % 4 == 0 && isPowerOfFour(n / 4);
    }
};
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return 0 ==(n &(n-1));
    }
};
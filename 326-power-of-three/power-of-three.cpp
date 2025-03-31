class Solution {
public:
    bool isPowerOfThree(int n) {
        // Base cases
        if (n == 1) return true;
        if (n <= 0 || n % 3 != 0) return false;

        // Recursive step
        return isPowerOfThree(n / 3);
    }
};
class Solution {
public:
    int sumOfDigits(int n) {
        int x = 0; 
        while(n > 0) {
            x += (n % 10) * (n % 10); 
            n /= 10; 
        }
        return x; 
    }

    bool isHappy(int n) {
        while(n > 4) {
            n = sumOfDigits(n); 
        }
        return n == 1; 
    }
};
class Solution {
public:
    double fun(double a, int b) {
        if (a == 0) return 0;
        if (b == 0) return 1;
        
        // Handle negative exponents
        long long t = b;
        if (b < 0) {
            t = -t;
            a = 1.0 / a;
        }
        
        // Efficient power calculation using squaring
        double result = 1.0;
        while (t > 0) {
            if (t % 2 == 1) {
                result *= a;
            }
            a *= a;
            t /= 2;
        }
        
        return result;
    }

    double myPow(double x, int n) {
        return fun(x, n);
    }
};

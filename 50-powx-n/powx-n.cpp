class Solution {
public:
    double fun(double a, long long b) {
        if (b == 0) return 1;
        if (b < 0) {
            return 1.0 / fun(a, -b);
        }
        
        double half = fun(a, b / 2);
        if (b % 2 == 0) {
            return half * half;
        } else {
            return half * half * a;
        }
    }

    double myPow(double x, int n) {
        return fun(x, n);
    }
};


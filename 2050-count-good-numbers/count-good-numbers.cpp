class Solution {
public:
    int countGoodNumbers(long long n) {
        long long MOD = 1e9 + 7;
        return (int)((power(5, (n + 1) / 2) * power(4, n / 2)) % MOD);
    }
private:
    long long power(long long x, long long y) {
        long long result = 1;
        long long MOD = 1e9 + 7;
        
        while (y > 0) {
            if (y % 2 == 1)
                result = (result * x) % MOD;
            x = (x * x) % MOD;
            y /= 2;
        }
        return result;
    }
};
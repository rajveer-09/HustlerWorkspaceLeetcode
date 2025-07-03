class Solution {
public:
    const int MOD = 1e9 + 7;

    long long binExp(long long a, long long b) {
        long long res = 1;
        a %= MOD;

        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }
    int countGoodNumbers(long long n) {
        long long oddPlaces = n / 2;
        long long evenPlaces = (n + 1) / 2;

        return (int)(binExp(4, oddPlaces) % MOD * binExp(5, evenPlaces) % MOD) % MOD;
    }
};
/*
n -> odd -> even pos = (odd + 1) / 2;
        -> odd pos = odd / 2;

        evens -> [0,2,4,6,8] | odd -> [2, 3, 5, 7];
*/
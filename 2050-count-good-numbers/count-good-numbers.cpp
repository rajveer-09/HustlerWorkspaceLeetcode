class Solution {
public:
    const int MOD = 1e9 + 7;

    long long binExp(long long a, long long b) {
        if (b == 0) return 1;

        long long half = binExp(a, b / 2);
        long long res = (half * half) % MOD;

        if (b & 1) res = (res * a) % MOD;

        return res;
    }

    int countGoodNumbers(long long n) {
        long long oddPlaces = n / 2;
        long long evenPlaces = (n + 1) / 2;

        return (int)((binExp(5, evenPlaces) * binExp(4, oddPlaces)) % MOD);
    }
};

/*
n -> odd -> even pos = (odd + 1) / 2;
        -> odd pos = odd / 2;

        evens -> [0,2,4,6,8] | odd -> [2, 3, 5, 7];
*/
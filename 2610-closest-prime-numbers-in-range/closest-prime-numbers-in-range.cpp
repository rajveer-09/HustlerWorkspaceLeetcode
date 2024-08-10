class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0) return false;
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        int ans1 = -1, ans2 = -1;
        int a1 = -1;
        int mini = INT_MAX;

        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                if (a1 != -1 && (i - a1) < mini) {
                    ans1 = a1;
                    ans2 = i;
                    mini = i - a1;
                }
                a1 = i;
            }
        }

        if (ans1 != -1 && ans2 != -1) {
            return {ans1, ans2};
        } else {
            return {-1, -1};
        }
    }
};

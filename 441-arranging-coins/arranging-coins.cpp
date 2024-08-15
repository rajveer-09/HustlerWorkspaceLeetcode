class Solution {
public:
    int arrangeCoins(int n) {
        long long i = 0, j = n;

        while (i <= j) {
            long long mid = i + (j - i) / 2;
            long long target = mid * (mid + 1) / 2;

            if (target == n) {
                return mid;
            } 
            else if (target > n) {
                j = mid - 1;
            } 
            else {
                i = mid + 1;
            }
        }
        return j;
    }
};

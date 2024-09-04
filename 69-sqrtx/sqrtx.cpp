class Solution {
public:
    int mySqrt(int n) {
        if (n <= 1)
            return n;

        int i = 0, j = n;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (mid == n / mid)
                return mid;

            else if (mid < n / mid)
                i = mid + 1;

            else
                j = mid - 1;
        }

        return j;
    }
};
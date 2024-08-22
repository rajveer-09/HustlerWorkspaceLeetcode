class Solution {
public:
    int numWaterBottles(int n, int e) {
        int total = n;

        while (n >= e) {
            total += n / e;
            n = (n / e) + (n % e);
        }

        return total;
    }
};

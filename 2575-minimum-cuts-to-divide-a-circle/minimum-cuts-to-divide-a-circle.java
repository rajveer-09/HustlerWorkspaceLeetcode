class Solution {
    public int numberOfCuts(int n) {
        if (n == 1) {
            return 0;  // No cuts needed for one slice
        }
        return n % 2 == 0 ? n / 2 : n;  // n/2 for even slices, n for odd slices
    }
}
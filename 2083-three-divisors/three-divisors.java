class Solution {
    public boolean isThree(int n) {
        if (n <= 1) return false;

        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                count++;
                if (i != n / i) count++;
            }
        }
        
        return count == 3;
    }
}

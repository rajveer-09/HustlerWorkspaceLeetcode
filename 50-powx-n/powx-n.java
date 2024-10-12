public class Solution {
    public double myPow(double x, int n) {
        long N = n;  // Convert to long to avoid overflow
        
        if (N < 0) {
            x = 1 / x;
            N = -N;  // Make the exponent positive
        }
        
        return fastPow(x, N);  // Recursive fast exponentiation
    }

    private double fastPow(double x, long n) {
        if (n == 0) {
            return 1.0;  // Base case: x^0 = 1
        }
        
        double half = fastPow(x, n / 2);  // Recursively compute x^(n/2)
        
        if (n % 2 == 0) {
            return half * half;  // If n is even, return square of half
        } else {
            return half * half * x;  // If n is odd, multiply an extra x
        }
    }
}
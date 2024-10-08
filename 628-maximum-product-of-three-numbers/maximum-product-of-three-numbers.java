class Solution {
    public int maximumProduct(int[] A) {
        int n = A.length;

        Arrays.sort(A);
        
        long a = A[0];
        long b = A[1];
        long c = A[n - 1];
        long d = A[n - 2];
        long e = A[n - 3];

        return (int) Math.max(a * b * c, c * d * e);
    }
}
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        boolean[] row = new boolean[m];
        boolean[] col = new boolean[n];

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == 0) {
                    row[r] = true;
                    col[c] = true;
                }
            }
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (row[r] || col[c]) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
}
class Solution {
    public boolean isValidSudoku(char[][] board) {
        // Check rows
        for (int i = 0; i < 9; i++) {
            boolean[] seen = new boolean[9];
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    if (seen[num]) {
                        return false;
                    }
                    seen[num] = true;
                }
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            boolean[] seen = new boolean[9];
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    if (seen[num]) {
                        return false;
                    }
                    seen[num] = true;
                }
            }
        }

        // Check 3x3 sub-boxes
        for (int box = 0; box < 9; box++) {
            boolean[] seen = new boolean[9];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = 3 * (box / 3) + i;
                    int col = 3 * (box % 3) + j;
                    if (board[row][col] != '.') {
                        int num = board[row][col] - '1';
                        if (seen[num]) {
                            return false;
                        }
                        seen[num] = true;
                    }
                }
            }
        }

        return true;
    }
}

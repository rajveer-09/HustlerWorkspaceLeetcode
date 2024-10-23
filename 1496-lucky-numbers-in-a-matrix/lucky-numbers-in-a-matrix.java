import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        List<Integer> luckyNumbers = new ArrayList<>();
        int[] rowMins = new int[matrix.length];
        
        // Find the minimum element in each row
        for (int i = 0; i < matrix.length; i++) {
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
            rowMins[i] = min;
        }
        
        // Check if the row minimum is the maximum in its column
        for (int i = 0; i < matrix.length; i++) {
            int min = rowMins[i];
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == min) {
                    boolean isMaxInColumn = true;
                    for (int k = 0; k < matrix.length; k++) {
                        if (matrix[k][j] > min) {
                            isMaxInColumn = false;
                            break;
                        }
                    }
                    if (isMaxInColumn) {
                        luckyNumbers.add(min);
                    }
                    break;
                }
            }
        }
        
        return luckyNumbers;
    }
}

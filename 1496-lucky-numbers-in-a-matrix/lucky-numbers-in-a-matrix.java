class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        List<Integer> luckyNumbers = new ArrayList<>();
        
        int[] rowMins = new int[matrix.length];
        
        for (int i = 0; i < matrix.length; i++) {
            int min = matrix[i][0]; 
            for (int j = 1; j < matrix[i].length; j++) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
            rowMins[i] = min; 
        }
        
        for (int i = 0; i < matrix.length; i++) {
            int minValue = rowMins[i];
         
            int colIndex = -1;
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == minValue) {
                    colIndex = j;
                    break;
                }
            }
           
            boolean isMaxInColumn = true;
            for (int k = 0; k < matrix.length; k++) {
                if (matrix[k][colIndex] > minValue) {
                    isMaxInColumn = false;
                    break;
                }
            }
            
            if (isMaxInColumn) {
                luckyNumbers.add(minValue);
            }
        }
        
        return luckyNumbers;
    }
    
}
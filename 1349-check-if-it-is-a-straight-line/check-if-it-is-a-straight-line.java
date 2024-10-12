class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];
        
        int dx = x1 - x0;
        int dy = y1 - y0;
        
        for (int i = 2; i < coordinates.length; i++) {
            int x = coordinates[i][0], y = coordinates[i][1];
            
            // Check if the slopes are equal using cross multiplication to avoid division
            if ((y - y0) * dx != (x - x0) * dy) {
                return false;
            }
        }
        
        return true;
    }
}

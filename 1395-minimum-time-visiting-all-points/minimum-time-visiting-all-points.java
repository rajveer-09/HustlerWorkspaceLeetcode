class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
         int totalTime = 0;

        for (int i = 0; i < points.length - 1; i++) {
            int[] point1 = points[i];
            int[] point2 = points[i + 1];
            totalTime += Math.max(Math.abs(point2[0] - point1[0]), Math.abs(point2[1] - point1[1]));
        }

        return totalTime;
    }
}
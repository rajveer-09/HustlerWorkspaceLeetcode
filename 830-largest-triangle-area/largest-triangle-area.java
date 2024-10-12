class Solution {
    public double largestTriangleArea(int[][] points) {
        double maxArea = 0;

        for (int i = 0; i < points.length - 2; i++) {
            for (int j = i + 1; j < points.length - 1; j++) {
                for (int k = j + 1; k < points.length; k++) {
                    int[] p1 = points[i];
                    int[] p2 = points[j];
                    int[] p3 = points[k];

                    double area = 0.5 * Math.abs(
                        p1[0] * (p2[1] - p3[1]) + 
                        p2[0] * (p3[1] - p1[1]) + 
                        p3[0] * (p1[1] - p2[1])
                    );

                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
            }
        }

        return maxArea;
    }
}

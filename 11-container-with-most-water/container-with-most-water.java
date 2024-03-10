class Solution {
    public int maxArea(int[] height) {
        int l = 0;
        int r = height.length - 1;
        int max = 0;
        
        while (l < r) {
            int minH = Math.min(height[l], height[r]);
            int area = minH * (r - l);
            if (area > max) {
                max = area;
            }
            while (l < r && height[l] <= minH) {
                l++;
            }
            while (l < r && height[r] <= minH) {
                r--;
            }
        }
        
        return max;
    }
};
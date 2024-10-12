class Solution {
    public int[] constructRectangle(int area) {
        int w = (int) Math.sqrt(area); // Start with the largest possible width less than or equal to the square root of the area
        while (area % w != 0) { // Decrease w until we find a width that evenly divides the area
            w--;
        }
        int l = area / w; // Compute the corresponding length
        return new int[]{l, w}; // Return the dimensions as an array
    }
}

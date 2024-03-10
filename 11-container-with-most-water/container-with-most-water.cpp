class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_area = 0;
        int left = 0, right = n - 1;

        while (left < right) {
            int h = min(height[left], height[right]);
            int area = h * (right - left);
            max_area = max(max_area, area);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};
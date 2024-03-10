class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_area = 0;

        for (int i = 0; i < n - 1; i++) {
            
            for (int j = i + 1; j < n; j++) {
                if (height[i]*(n-i-1) < max_area) break;
                int a = min(height[i], height[j]);
                int area = a * (j - i);
                if (area > max_area) max_area = area;
            }
        }
        return max_area;
    }
};
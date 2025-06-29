class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int start) {
        int n = image.size();
        int m = image[0].size();
        
        if (i < 0 || i >= n || j < 0 || j >= m || image[i][j] != start) {
            return;
        }

        image[i][j] = color;

        dfs(image, i + 1, j, color, start);
        dfs(image, i - 1, j, color, start);
        dfs(image, i, j + 1, color, start);
        dfs(image, i, j - 1, color, start);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        if (start == color) return image; //important fix
        dfs(image, sr, sc, color, start);
        
        return image;
    }
};
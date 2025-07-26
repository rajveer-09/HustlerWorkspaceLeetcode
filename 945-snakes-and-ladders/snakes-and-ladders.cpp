class Solution {
public:
    pair<int, int> getCoordinate(int num, int n) {
        int rowFromBottom = (num - 1) / n;
        int colInRow = (num - 1) % n;

        int actualRow = n - 1 - rowFromBottom;
        int actualCol = (rowFromBottom % 2 == 0) ? colInRow : (n - 1 - colInRow);

        return {actualRow, actualCol};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> vis(n * n + 1, 0);
        queue<pair<int, int>> q;

        q.push({1, 0});
        vis[1] = 1;

        while (!q.empty()) {
            auto [node, steps] = q.front();
            q.pop();

            if (node == n * n) return steps;

            for (int i = 1; i <= 6; ++i) {
                int newNode = node + i;
                if (newNode > n * n) continue;

                auto [row, col] = getCoordinate(newNode, n);
                if (board[row][col] != -1) {
                    newNode = board[row][col];
                }

                if (!vis[newNode]) {
                    vis[newNode] = 1;
                    q.push({newNode, steps + 1});
                }
            }
        }

        return -1;
    }
};
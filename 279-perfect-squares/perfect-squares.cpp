class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        queue<int> q;
        vector<bool> visited(n + 1, false);

        q.push(n);
        visited[n] = true;

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            level++;

            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                for (int sq : squares) {
                    int next = curr - sq;
                    if (next == 0) return level;
                    if (next < 0) break;

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        return level;
    }
};
/*

<- STATE BASED BFS ->

1. We start from number n.
2. At each step, we subtract a perfect square (1, 4, 9, … ≤ n).
3. This gives us the “next states”.
4. If we reach 0, we are done.
5. The number of steps taken = the number of perfect squares used.

*/
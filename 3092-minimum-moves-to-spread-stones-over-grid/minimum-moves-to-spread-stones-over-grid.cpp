class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<int> start;
        for (auto& row : grid)
            for (int val : row)
                start.push_back(val);

        vector<int> target(9, 1);
        queue<pair<vector<int>, int>> q;
        set<vector<int>> visited;

        q.push({start, 0});
        visited.insert(start);

        vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        auto idx = [&](int i, int j) { return i * 3 + j; };

        while (!q.empty()) {
            auto [state, steps] = q.front();
            q.pop();
            if (state == target)
                return steps;

            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int pos = idx(i, j);
                    if (state[pos] > 1) {
                        for (auto [dx, dy] : dirs) {
                            int ni = i + dx, nj = j + dy;
                            if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3) {
                                int npos = idx(ni, nj);
                                vector<int> new_state = state;
                                new_state[pos]--;
                                new_state[npos]++;
                                if (!visited.count(new_state)) {
                                    visited.insert(new_state);
                                    q.push({new_state, steps + 1});
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};

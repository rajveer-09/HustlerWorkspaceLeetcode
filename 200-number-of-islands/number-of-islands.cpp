class DSU {
    vector<int> Parent, Size;
public:
    DSU(int n) {
        Parent.resize(n + 1);
        Size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int find(int node) {
        if (node != Parent[node]) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return false;
        if (Size[pu] >= Size[pv]) {
            Size[pu] += Size[pv];
            Parent[pv] = pu;
        } else {
            Size[pv] += Size[pu];
            Parent[pu] = pv;
        }
        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        DSU dsu(ROWS * COLS);

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int islands = 0;

        auto index = [&](int r, int c) {
            return r * COLS + c;
        };

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1') {
                    islands++;

                    for (auto& d : directions) {
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if (nr >= 0 && nc >= 0 && nr < ROWS &&
                            nc < COLS && grid[nr][nc] == '1') {
                            if (dsu.unionBySize(index(r, c), index(nr, nc))) {
                                islands--;
                                cout<<islands<<" ";
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};
/*

->  The algorithm assumes that every '1' is a new, separate island. This is why it initializes islands to 0 and increments it (islands++) for every '1' it encounters.

-> When the algorithm finds two adjacent '1's, it means they belong to the same island. It then performs a union operation on their corresponding sets.

->  If the union operation is successful (meaning the two cells were in different sets and are now merged), it means we have just discovered that two previously assumed separate islands are actually a single one. To correct our count, we must decrement the island counter (islands--).

*/
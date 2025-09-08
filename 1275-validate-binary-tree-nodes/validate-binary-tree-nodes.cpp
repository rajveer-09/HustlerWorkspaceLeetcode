class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    bool unite(int u, int v) {
        int x = find(u);
        int y = find(v);

        if (x == y) return false;

        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            rank[x]++;
        }

        return true;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);
        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            int left = leftChild[i];
            int right = rightChild[i];

            if (left != -1) {
                inDegree[left]++;
                if (inDegree[left] > 1 || !dsu.unite(i, left)) return false;
            }

            if (right != -1) {
                inDegree[right]++;
                if (inDegree[right] > 1 || !dsu.unite(i, right)) return false;
            }
        }

        int root = -1;
        int components = 0;
        
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                if (root != -1) return false;
                root = i;
            }
            if (dsu.parent[i] == i) {
                components++;
            }
        }

        return root != -1 && components == 1;
    }
};
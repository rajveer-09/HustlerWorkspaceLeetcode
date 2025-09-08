class DSU {
private:
    vector<int> parent, rankv;
public:
    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false; // cycle
        if (rankv[pu] < rankv[pv]) {
            parent[pu] = pv;
        } else if (rankv[pu] > rankv[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rankv[pu]++;
        }
        return true;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DSU dsu(n);
        vector<int> indeg(n, 0);

        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (++indeg[leftChild[i]] > 1) return false; // multiple parents
                if (!dsu.unite(i, leftChild[i])) return false; // cycle
            }
            if (rightChild[i] != -1) {
                if (++indeg[rightChild[i]] > 1) return false; // multiple parents
                if (!dsu.unite(i, rightChild[i])) return false; // cycle
            }
        }

        // root check: exactly one node with indegree 0
        int rootCount = 0;

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) rootCount++;
        }
        
        if (rootCount != 1) return false;

        // connected check: all nodes must share one root
        int root = dsu.find(0);
        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root) return false;
        }

        return true;
    }
};

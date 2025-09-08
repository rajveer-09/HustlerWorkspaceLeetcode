class DisjointSet {
private:
    vector<int> rank;
    vector<int> parent;
public:
    vector<int> size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]);
    }

    bool find(int u, int v) {
        return (findUPar(u) == findUPar(v));
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } 
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet obj(n);

        for(auto ed : edges){
            if(!obj.find(ed[0], ed[1])){
                obj.unionBySize(ed[0], ed[1]);
            }
        }

        unordered_set<int>st;
        long long ans = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            int p = obj.findUPar(i);

            if(st.count(p)) continue;

            st.insert(p);

            int sz = obj.size[p];

            ans += (n - cnt - sz)*1LL * sz;
            cnt += sz;
        }

        return ans;
    }
};
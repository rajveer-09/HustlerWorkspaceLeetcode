class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        UnionFind uf(n);

        for (const auto& p : pairs) {
            uf.unite(p[0], p[1]);
        }

        map<int, vector<int>> components;
        for (int i = 0; i < n; ++i) {
            components[uf.find(i)].push_back(i);
        }

        string result = s;

        for (auto const& [root, indices] : components) {
            string component_chars;

            for (int idx : indices) {
                component_chars += s[idx];
            }
            sort(component_chars.begin(), component_chars.end());
            
            for (int i = 0; i < indices.size(); ++i) {
                result[indices[i]] = component_chars[i];
            }
        }
        
        return result;
    }
};
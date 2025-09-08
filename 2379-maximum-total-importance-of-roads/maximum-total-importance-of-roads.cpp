class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n,0);

        long long val = 0;

        for (int i = 0; i < roads.size(); i++){
            degree[roads[i][0]] += 1;
            degree[roads[i][1]] += 1;
        }

        sort(degree.begin(),degree.end());

        int p = 1;

        for (int m = 0; m < degree.size(); m++){
            val += degree[m]*p;
            p += 1;
        }

        return val;
    }
};

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_count(n+1);
        vector<bool> cant_be_judge(n+1);
        for (auto& t : trust) {
            trust_count[t[1]]++;
            cant_be_judge[t[0]] = true;
        }
        for (int i = 1; i <= n; ++i) {
            if (trust_count[i] == n-1 && !cant_be_judge[i])
                return i;
        }
        return -1;
    }
};
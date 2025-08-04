class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        int max_s = 0;

        for (int s : score) {
            max_s = max(max_s, s);
        }

        vector<int> s_map(max_s + 1, -1);
        for (int i = 0; i < n; ++i) {
            s_map[score[i]] = i;
        }

        vector<string> ans(n);
        int rank = 1;

        for (int s = max_s; s >= 0; --s) {
            if (s_map[s] != -1) {
                int idx = s_map[s];
                if (rank == 1) {
                    ans[idx] = "Gold Medal";
                } else if (rank == 2) {
                    ans[idx] = "Silver Medal";
                } else if (rank == 3) {
                    ans[idx] = "Bronze Medal";
                } else {
                    ans[idx] = to_string(rank);
                }
                rank++;
            }
        }
        return ans;
    }
};
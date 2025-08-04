class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        int maxi = -1;

        for (int num : score) {
            maxi = max(maxi, num);
        }

        vector<int> map(maxi + 1, -1);
        for (int i = 0; i < n; i++) {
            map[score[i]] = i;
        }

        vector<string> ans(n);
        int rank = 1;

        for (int i = maxi; i >= 0; i--) {
            if (map[i] != -1) {
                int idx = map[i];
                
                if (rank == 1) {
                    ans[idx] = "Gold Medal";
                } 
                else if (rank == 2) {
                    ans[idx] = "Silver Medal";
                } 
                else if (rank == 3) {
                    ans[idx] = "Bronze Medal";
                } 
                else {
                    ans[idx] = to_string(rank);
                }

                rank++;

                if (rank > n) break;

            }
        }

        return ans;
    }
};

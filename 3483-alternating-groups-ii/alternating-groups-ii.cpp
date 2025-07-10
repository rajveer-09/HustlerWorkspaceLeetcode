class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        if (n < k) return 0;

        int cnt = 1;
        int ans = 0;

        for (int i = 1; i < n * 2; ++i) {
            int prev = colors[(i - 1) % n];
            int curr = colors[i % n];

            if(cnt >= k) ans++;

            if (curr != prev) {
                cnt++;
            } 
            else {
                cnt = 1;
            }

            if (i == n + k  - 1) {
                break;
            }
        }

        return ans;
    }
};
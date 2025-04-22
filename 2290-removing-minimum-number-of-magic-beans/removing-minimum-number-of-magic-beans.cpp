class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());

        long long sum = 0;
        long long n = beans.size();

        for (int i = 0; i < n; i++) {
            sum += beans[i];
        }

        long long ans = sum;

        for (int i = 0; i < n; i++) {
            long long curans = sum - (long long)(n - i) * beans[i];
            if (curans < ans) {
                ans = curans;
            }
        }
        return ans;
    }
};
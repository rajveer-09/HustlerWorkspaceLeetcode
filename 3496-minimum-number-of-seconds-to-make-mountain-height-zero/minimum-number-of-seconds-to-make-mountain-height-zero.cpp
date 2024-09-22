class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto findNum = [](long long bound) {
            return (int)((-1 + sqrt(1 + 8 * bound)) / 2);
        };

        // Helper function to calculate the total height reduced in given time
        auto heightReduced = [&](long long time) {
            long long ans = 0;
            for (int wt : workerTimes) {
                ans += findNum(time / wt);
            }
            return ans;
        };

        long long l = 1, r = (1LL << 55) - 1;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (heightReduced(mid) >= mountainHeight) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
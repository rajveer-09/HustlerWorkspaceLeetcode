vector<long long> generatePrimes(long long n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<long long> primes;
    for (long long i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        if (nums.size() <= 1) return -1;

        unordered_map<long long, long long> minPos, maxPos;
        vector<long long> primes = generatePrimes(1000);

        auto updateFactorPositions = [&](long long n, long long idx) {
            for (long long p : primes) {
                if (p * p > n) break;
                if (n % p == 0) {
                    while (n % p == 0) n /= p;
                    if (minPos.find(p) == minPos.end()) {
                        minPos[p] = idx;
                        maxPos[p] = idx;
                    } else {
                        maxPos[p] = idx;
                    }
                }
            }
            if (n > 1) {
                if (minPos.find(n) == minPos.end()) {
                    minPos[n] = idx;
                    maxPos[n] = idx;
                } else {
                    maxPos[n] = idx;
                }
            }
        };

        for (long long i = 0; i < nums.size(); ++i) {
            updateFactorPositions(nums[i], i);
        }

        vector<pair<long long, int>> events;
        for (const auto& [factor, pos] : minPos) {
            events.push_back({pos, 0});
            events.push_back({maxPos[factor], 1});
        }

        sort(events.begin(), events.end());

        if (events.empty() || events[0].first != 0) return 0;

        int count = 0;
        for (const auto& [pos, type] : events) {
            if (type == 0) {
                ++count;
            } else {
                --count;
                if (count == 0 && pos + 1 < nums.size()) {
                    return pos;
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> sieve(int max_num) {
        vector<int> spf(max_num + 1);  // Smallest prime factor for every number
        for (int i = 2; i <= max_num; i++) spf[i] = i;
        for (int i = 2; i * i <= max_num; i++) {
            if (spf[i] == i) {  // i is prime
                for (int j = i * i; j <= max_num; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
        return spf;
    }

    void primeFreq(int x, unordered_map<int, int> &mp, const vector<int>& spf) {
        while (x != 1) {
            mp[spf[x]] += 1;
            x /= spf[x];
        }
    }

    int findValidSplit(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        vector<int> spf = sieve(max_num);

        unordered_map<int, int> global_freq;

        // Calculate overall frequency of prime factors
        for (int num : nums) {
            primeFreq(num, global_freq, spf);
        }

        unordered_map<int, int> left_freq;

        for (int i = 0; i < nums.size() - 1; i++) {  // No need to check the last element
            unordered_map<int, int> temp_freq;
            primeFreq(nums[i], temp_freq, spf);

            // Move prime factors from right to left
            for (auto& p : temp_freq) {
                left_freq[p.first] += p.second;
                global_freq[p.first] -= p.second;

                if (global_freq[p.first] == 0) {
                    global_freq.erase(p.first);
                }
            }

            // Check if there's no intersection between left and right parts
            bool valid_split = true;
            for (auto& p : left_freq) {
                if (global_freq.count(p.first)) {
                    valid_split = false;
                    break;
                }
            }

            if (valid_split) {
                return i;
            }
        }

        return -1;
    }
};
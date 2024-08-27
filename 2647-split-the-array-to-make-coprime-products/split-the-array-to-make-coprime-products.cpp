#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    // Function to compute smallest prime factors (SPF) using the Sieve of Eratosthenes
    std::vector<int> sieve(int max_num) {
        std::vector<int> spf(max_num + 1);
        for (int i = 2; i <= max_num; ++i) spf[i] = i;
        for (int i = 2; i * i <= max_num; ++i) {
            if (spf[i] == i) {  // i is prime
                for (int j = i * i; j <= max_num; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
        return spf;
    }

    // Function to compute prime factor frequencies
    void primeFreq(int x, std::unordered_map<int, int> &freq, const std::vector<int>& spf) {
        while (x > 1) {
            int prime = spf[x];
            freq[prime]++;
            x /= prime;
        }
    }

    int findValidSplit(std::vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        // Determine maximum number in the array for sieve size
        int max_num = *std::max_element(nums.begin(), nums.end());
        std::vector<int> spf = sieve(max_num);

        // Global frequency of prime factors
        std::unordered_map<int, int> global_freq;

        // Calculate overall frequency of prime factors for the entire array
        for (int num : nums) {
            primeFreq(num, global_freq, spf);
        }

        std::unordered_map<int, int> left_freq;

        // Iterate to find a valid split point
        for (int i = 0; i < nums.size() - 1; ++i) {
            std::unordered_map<int, int> temp_freq;
            primeFreq(nums[i], temp_freq, spf);

            // Update left_freq and global_freq
            for (const auto& [prime, count] : temp_freq) {
                left_freq[prime] += count;
                global_freq[prime] -= count;

                if (global_freq[prime] == 0) {
                    global_freq.erase(prime);
                }
            }

            // Check for valid split
            bool valid_split = true;
            for (const auto& [prime, count] : left_freq) {
                if (global_freq.count(prime)) {
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

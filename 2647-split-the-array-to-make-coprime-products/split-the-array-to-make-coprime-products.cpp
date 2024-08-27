class Solution {
public:
    void primeFreq(int x, unordered_map<int, int> &mp) {
        for (int i = 2; i * i <= x; i++) {
            while (x % i == 0) {
                mp[i] += 1;
                x /= i;
            }
        }
        if (x > 1) {  // If x is a prime number
            mp[x] += 1;
        }
    }

    int findValidSplit(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        unordered_map<int, int> global_freq;

        // Calculate overall frequency of prime factors
        for (int num : nums) {
            unordered_map<int, int> temp_freq;
            primeFreq(num, temp_freq);
            for (auto& p : temp_freq) {
                global_freq[p.first] += p.second;
            }
        }

        unordered_map<int, int> left_freq;
        unordered_map<int, int> active_factors;  // Tracks factors that are still active in the right part

        for (int i = 0; i < nums.size() - 1; i++) {  // No need to check the last element
            unordered_map<int, int> temp_freq;
            primeFreq(nums[i], temp_freq);

            for (auto& p : temp_freq) {
                left_freq[p.first] += p.second;
                global_freq[p.first] -= p.second;
                if (global_freq[p.first] == 0) {
                    global_freq.erase(p.first);
                } else {
                    active_factors[p.first] = 1;  // Mark the factor as active on the right side
                }
            }

            // Check if any prime factor is still active in the right part
            bool valid_split = true;
            for (auto& factor : active_factors) {
                if (global_freq.count(factor.first)) {
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
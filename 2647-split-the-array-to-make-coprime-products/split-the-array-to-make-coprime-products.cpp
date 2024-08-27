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
            primeFreq(num, global_freq);
        }

        unordered_map<int, int> left_freq;

        for (int i = 0; i < nums.size() - 1; i++) {  // No need to check the last element
            unordered_map<int, int> temp_freq;
            primeFreq(nums[i], temp_freq);

            // Move prime factors from right to left
            for (auto& p : temp_freq) {
                left_freq[p.first] += p.second;
                global_freq[p.first] -= p.second;

                if (global_freq[p.first] == 0) {
                    global_freq.erase(p.first);
                }
            }

            // Check if left and right are coprime
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

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;

        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        while (!freq.empty()) {
            int start = freq.begin()->first;

            for (int i = 0; i < k; i++) {
                int curr = start + i;

                if (freq[curr] == 0) return false;

                freq[curr]--;

                if (freq[curr] == 0) {
                    freq.erase(curr);
                }
            }
        }

        return true;
    }
};
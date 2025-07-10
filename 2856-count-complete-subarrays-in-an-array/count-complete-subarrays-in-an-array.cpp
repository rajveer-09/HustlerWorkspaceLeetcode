class Solution {
public:
    int countAtMost(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int st = 0, count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;

            while (freq.size() > k) {
                freq[nums[st]]--;
                if (freq[nums[st]] == 0) {
                    freq.erase(nums[st]);
                }
                st++;
            }

            count += (i - st + 1);
        }

        return count;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> distinct(nums.begin(), nums.end());
        int totalDistinct = distinct.size();

        int c1 = countAtMost(nums, totalDistinct);
        int c2 = countAtMost(nums, totalDistinct - 1);

        return  c1 - c2;
    }
};

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        unordered_map<int, int> counts;
        for (int i = 0; i < sortedNums.size(); ++i) {
        // Only set the count for the first occurrence of each number
            if (counts.find(sortedNums[i]) == counts.end()) {
                counts[sortedNums[i]] = i;
            }
        }
        vector<int> ans;
        for (int num : nums) {
        ans.push_back(counts[num]);
        }
        return ans;
    }

};
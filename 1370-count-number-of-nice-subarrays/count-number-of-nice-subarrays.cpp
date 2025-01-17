class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt = 0, ans = 0;
        unordered_map<int, int> countMap;
        countMap[0] = 1; // Initialize with a count of 1 for the initial sum of 0

        for(int num : nums){
            cnt += num & 1; // Increment count if the number is odd
            if(countMap.find(cnt - k) != countMap.end()) {
                ans += countMap[cnt - k];
            }
            countMap[cnt]++;
        }

        return ans;
    }
};

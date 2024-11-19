class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK){
        int n = nums.size();
        long long cnt = 0;
        int minPos = -1, maxPos = -1, culpritIdx = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                culpritIdx = i;
            }
            if (nums[i] == minK) {
                minPos = i;
            }
            if (nums[i] == maxK) {
                maxPos = i;
            }
            cnt += max(0, min(minPos, maxPos) - culpritIdx);
        }

        return cnt;
    }
};
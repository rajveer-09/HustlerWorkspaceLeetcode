class Solution {
public:
    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = n + 1;

        int left = 0, right = 0, sum = 0;
        while (right < n) {
            
            while (sum < target && right < n)
                sum += nums[right++];

            while (sum >= target && left < n) {
                
                minLen = min(right - left, minLen);

                sum -= nums[left++];
            }
        }

        return minLen == n + 1 ? 0 : minLen;
    }
};
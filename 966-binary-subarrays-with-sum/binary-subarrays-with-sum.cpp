class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        ios_base::sync_with_stdio(false);
        int n = nums.size();
        int count = 0;
        int left = 0;
        int right = 0;
        int currentSum = 0;

        while (right < n) {
            // Add the current element to the currentSum
            currentSum += nums[right];
            
            // Move the left pointer to shrink the window if necessary
            while (left <= right && currentSum > goal) {
                currentSum -= nums[left];
                left++;
            }

            // If the current sum equals the goal, count the number of subarrays
            if (currentSum == goal) {
                // Count subarrays starting from each index from left to right
                int tempLeft = left;
                while (tempLeft <= right && currentSum == goal) {
                    count++;
                    currentSum -= nums[tempLeft];
                    tempLeft++;
                }
                currentSum = goal; // Restore the current sum for the next iteration
            }

            // Move the right pointer to expand the window
            right++;
        }

        return count;
    }
};
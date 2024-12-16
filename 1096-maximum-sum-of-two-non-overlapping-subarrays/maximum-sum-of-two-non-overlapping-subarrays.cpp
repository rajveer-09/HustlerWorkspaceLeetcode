#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        int maxSum = 0;

        // Iterate over all possible starting points for the first subarray of length firstLen
        for (int i = 0; i <= n - firstLen; ++i) {
            int firstSum = 0;
            // Calculate the sum of the first subarray
            for (int k = i; k < i + firstLen; ++k) {
                firstSum += nums[k];
            }

            // Iterate over all possible starting points for the second subarray of length secondLen
            for (int j = 0; j <= n - secondLen; ++j) {
                // Check if the second subarray overlaps with the first subarray
                if (j + secondLen <= i || j >= i + firstLen) {
                    int secondSum = 0;
                    // Calculate the sum of the second subarray
                    for (int k = j; k < j + secondLen; ++k) {
                        secondSum += nums[k];
                    }
                    // Update the maximum sum
                    maxSum = max(maxSum, firstSum + secondSum);
                }
            }
        }

        return maxSum;
    }
};

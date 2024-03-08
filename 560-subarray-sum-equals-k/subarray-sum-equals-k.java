public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        int[] prefixSum = new int[nums.length + 1];
        prefixSum[0] = 0;

        // Calculate prefix sum
        for (int i = 1; i <= nums.length; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // Check subarrays sum
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                int sum = prefixSum[end] - prefixSum[start];
                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
}

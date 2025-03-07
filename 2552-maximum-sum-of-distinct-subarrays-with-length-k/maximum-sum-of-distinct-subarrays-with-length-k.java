class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        int st = 0;
        long sum = 0, ans = 0;
        Map<Integer, Integer> freq = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
            sum += nums[i];

            // Ensure all elements are unique
            while (freq.get(nums[i]) > 1) {
                freq.put(nums[st], freq.get(nums[st]) - 1);
                sum -= nums[st];
                if (freq.get(nums[st]) == 0) freq.remove(nums[st]);
                st++;
            }

            // If window size is exactly k, check for max sum
            if (i - st + 1 == k) {
                if (freq.size() == k) {
                    ans = Math.max(ans, sum);
                }

                // Remove leftmost element to slide the window
                freq.put(nums[st], freq.get(nums[st]) - 1);
                sum -= nums[st];
                if (freq.get(nums[st]) == 0) freq.remove(nums[st]);
                st++;
            }
        }

        return ans;
    }
}
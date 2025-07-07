class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int res = 0, left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 == 1) k--;

            while (k < 0) {
                if (nums[left] % 2 == 1) k++;
                left++;
            }

            res += right - left + 1;
        }

        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

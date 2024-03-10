class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int countZero = 0;
        while (left < nums.size() && nums[left] == 0) {
            countZero++;
            left++;
        }
        int posCount = nums.size() - left;
        int negCount = left - countZero;
        return max(posCount, negCount);
    }
};
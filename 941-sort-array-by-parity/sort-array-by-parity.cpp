class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if ((nums[left] & 1) && !(nums[right] & 1)) {
                swap(nums[left], nums[right]);
                ++left;
                --right;
            } else {
                if (!(nums[left] & 1)) ++left;
                if (nums[right] & 1) --right;
            }
        }
        return nums;
    }
};
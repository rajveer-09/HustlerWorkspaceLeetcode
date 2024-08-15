class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;

        while (i < j) {
            int mid = i + (j - i) / 2;

            if (mid & 1) {
                mid--;
            }

            if (nums[mid] == nums[mid + 1]) {
                i = mid + 2;
            } 
            else {
                j = mid;
            }
        }
        return nums[i];
    }
};

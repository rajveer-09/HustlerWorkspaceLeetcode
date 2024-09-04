class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                cnt++;
                if (cnt > 1)
                    return false;

                if (i > 1 && nums[i] < nums[i - 2]) {
                    nums[i] = nums[i - 1];
                }
            }
        }

        return true;
    }
};
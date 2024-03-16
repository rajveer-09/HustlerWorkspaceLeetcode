class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        int balance = 0;
        vector<int> index(2 * nums.size() + 1, -2);
        index[nums.size()] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            balance += (nums[i] == 0) ? -1 : 1;
            if (index[balance + nums.size()] == -2) {
                index[balance + nums.size()] = i;
            } else {
                maxLength = max(maxLength, i - index[balance + nums.size()]);
            }
        }

        return maxLength;
    }
};
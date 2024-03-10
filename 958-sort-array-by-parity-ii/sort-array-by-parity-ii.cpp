class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int evenIdx = 0, oddIdx = 1;

        for (int i = 0; i < n; ++i) {
            if ((nums[i] & 1 )== 0) {
                result[evenIdx] = nums[i];
                evenIdx += 2;
            }
            else {
                result[oddIdx] = nums[i];
                oddIdx += 2;
            }
        }
    return result;
    }
};
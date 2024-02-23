class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt = 0;
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int d = nums[j] - nums[i];
                if (d == diff && nums[k] - nums[j] == diff) {
                    cnt++;
                    j++;
                    k--;
                } else if (d < diff) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return cnt;
    }
};
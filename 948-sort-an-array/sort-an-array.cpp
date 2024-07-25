class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> counting(2 * 50000 + 1, 0);
        for (int num : nums) {
            // we add 5 * 10^4 because for smallest possible element -5 * 10^4 index must be 0
            counting[num + 50000]++;
        }
        int write_ind = 0;
        for (int number_ind = 0; number_ind < counting.size(); ++number_ind) {
            int freq = counting[number_ind];
            while (freq != 0) {
                nums[write_ind] = number_ind - 50000;
                write_ind++;
                freq--;
            }
        }
        return nums;
    }
};
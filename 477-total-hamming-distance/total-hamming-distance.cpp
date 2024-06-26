class Solution {
public:

    int totalHammingDistance(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i = 0 ; i < 32 ; i++){
            int cnt_bit1 = 0;
            for(int num : nums){
                cnt_bit1 += (num>>i) & 1; 
            }
            res += cnt_bit1 * (n-cnt_bit1);
        }
        return res;
    }
};
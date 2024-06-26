class Solution {
public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    }
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i = 0 ; i < 32 ; i++){
            int number_of_bit_1 = 0;
            for(int num : nums){
                number_of_bit_1 += (num>>i) & 1; 
            }
            res += number_of_bit_1 * (n-number_of_bit_1);
        }
        return res;
    }
};
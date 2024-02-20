class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
    
    // Calculate the XOR of all numbers from 0 to n
    int xor_all = 0;
    for (int i = 0; i <= n; ++i) {
        xor_all ^= i;
    }
    
    // XOR all numbers in the array
    for (int num : nums) {
        xor_all ^= num;
    }
    
    // The remaining number is the missing one
    return xor_all;
    }
};
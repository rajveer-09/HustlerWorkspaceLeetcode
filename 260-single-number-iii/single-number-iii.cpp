class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorResult = 0;
        
        // Step 1: Calculate XOR of all elements in nums
        for (int num : nums) {
            xorResult ^= num;
        }
        
        // Step 2: Find the rightmost set bit in xorResult
        int rightmostSetBit = 1;
        while ((rightmostSetBit & xorResult) == 0) {
            rightmostSetBit <<= 1;
        }
        
        // Step 3: Initialize variables to store the two unique numbers
        int num1 = 0, num2 = 0;
        
        // Step 4: Partition nums based on the rightmost set bit and find the two numbers
        for (int num : nums) {
            if (num & rightmostSetBit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        
        // Step 5: Return the two numbers in any order
        return {num1, num2};
    }
};

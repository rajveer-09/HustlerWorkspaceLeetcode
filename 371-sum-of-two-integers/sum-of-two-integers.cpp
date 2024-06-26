class Solution {
public:
    int getSum(int a, int b) {
        int sum = (a ^ b);
        int carry = (a & b) << 1;
        while(carry!=0){
            int temp = sum;
            sum ^= carry;
            carry = (carry & temp) << 1;
        }
        return sum;
    }
};
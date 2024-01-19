class Solution {
public:
    int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int sumIndicesWithKSetBits(std::vector<int>& nums, int k) {
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        // Count the number of set bits in the binary representation of the index
        int count = countSetBits(i);

        if (count == k) {
            sum += nums[i];
        }
    }

    return sum;
    }
};
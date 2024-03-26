class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int smallestPositive = 1;
        
        for (int num : nums) {
            if (num == smallestPositive) {
                ++smallestPositive;
            }
        }
        return smallestPositive;
    }
};

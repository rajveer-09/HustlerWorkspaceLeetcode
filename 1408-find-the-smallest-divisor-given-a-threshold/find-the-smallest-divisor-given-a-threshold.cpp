#include <vector>
#include <algorithm>

class Solution {
public:
    int smallestDivisor(std::vector<int>& nums, int threshold) {
        int left = 1;
        int right = *std::max_element(nums.begin(), nums.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int sum = calculateSum(nums, mid);
            
            if (sum > threshold) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
private:
    int calculateSum(const std::vector<int>& nums, int divisor) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;
        }
        return sum;
    }
};

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int left = 1, right = nums.size(), result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int num : nums) {
                if (num >= mid) {
                    count++;
                }
            }
            if (count == mid) {
                result = mid;
                break;
            } else if (count < mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
};
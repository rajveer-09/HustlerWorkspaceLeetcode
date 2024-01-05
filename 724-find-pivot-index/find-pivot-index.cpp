class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
       int arrsum = 0;
    for (int i = 0; i < nums.size(); i++) {
        arrsum += nums[i];
    }

    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (sum == (arrsum - nums[i])) {
            return i;
        }
        sum += nums[i];
        arrsum -= nums[i];
    }

    return -1;
    }
};
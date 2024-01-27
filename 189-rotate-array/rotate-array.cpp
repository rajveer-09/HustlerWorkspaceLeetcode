class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
    k %= n; // Calculate effective rotation count

    // Create a temporary array to store rotated elements
    vector<int> temp(nums.begin() + n - k, nums.end());

    // Shift elements to the right
    for (int i = n - k - 1; i >= 0; --i) {
        nums[i + k] = nums[i];
    }

    // Copy rotated elements from the temporary array
    for (int i = 0; i < k; ++i) {
        nums[i] = temp[i];
    }
    }
};
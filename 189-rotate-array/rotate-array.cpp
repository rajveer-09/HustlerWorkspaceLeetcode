class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
    k %= n; // Calculate effective rotation count

    // Reverse the entire array
    for (int i = 0; i < n / 2; ++i) {
        swap(nums[i], nums[n - i - 1]);
    }

    // Reverse the first k elements
    for (int i = 0; i < k / 2; ++i) {
        swap(nums[i], nums[k - i - 1]);
    }

    // Reverse the remaining elements
    for (int i = k; i < (n + k) / 2; ++i) {
        swap(nums[i], nums[n - i - 1 + k]);
    }
    }
};
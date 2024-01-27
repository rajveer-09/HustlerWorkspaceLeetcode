class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

    reverse(nums.begin(), nums.end()); // Reverse the entire array
    reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements
    reverse(nums.begin() + k, nums.end()); // Reverse the remaining elements
    }
};
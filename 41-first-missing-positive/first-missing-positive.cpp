class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();

        // Place each number in its correct position
        for (int i = 0; i < n; i++) {
            while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // Find the first missing positive integer
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }

        // If all positions are correct, return n + 1
        return n + 1;
    }
};

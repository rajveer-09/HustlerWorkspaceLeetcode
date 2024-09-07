class Solution {
public:
    int findMin(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        int low = 0, high = arr.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {

            int mid = (low + high) / 2;

            // Sorted Portion ka min utha lo 
            if (arr[low] <= arr[mid]) {
                ans = min(ans, arr[low]);
                low = mid + 1;
            } 
            else {
                // Agar right side sorted hai toh mid uska min hoga
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};
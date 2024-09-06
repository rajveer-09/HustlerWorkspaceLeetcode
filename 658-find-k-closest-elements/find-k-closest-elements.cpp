class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n - k;
        
        // Binary search to find the starting point of the closest elements
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        
        // The result is the subarray starting from 'left' with length 'k'
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

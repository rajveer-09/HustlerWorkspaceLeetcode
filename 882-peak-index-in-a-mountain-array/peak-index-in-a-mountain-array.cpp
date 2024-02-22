class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size(), s = 0, e = n - 1;

        while(s <= e) {
            int m = (s + e) / 2;
            int left = -1e9, right = -1e9;
            if(m - 1 >= 0) left = arr[m - 1];
            if(m + 1 < n) right = arr[m + 1];

            if(left < arr[m] && arr[m] > right) {
                return m;
            }
            left > arr[m] ? e = m - 1 : s = m + 1;
        }
        return -1;
    }
};
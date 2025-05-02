class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // Always binary search on the smaller array
        if (n > m) return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = n;

        while (low <= high) {
            // left me chhotey waale ke kitne aaynge about median
            int Px = low + (high - low) / 2;
            // bache huye left ke elemnt bade arr se aynge
            int Py = (n + m + 1) / 2 - Px;

            int x1 = (Px == 0) ? INT_MIN : nums1[Px - 1];
            int x2 = (Px == n) ? INT_MAX : nums1[Px];

            int y1 = (Py == 0) ? INT_MIN : nums2[Py - 1];
            int y2 = (Py == m) ? INT_MAX : nums2[Py];

            if (x1 <= y2 && y1 <= x2) {
                if ((n + m) % 2 == 0) {
                    return (max(x1, y1) + min(x2, y2)) / 2.0;
                } else {
                    return max(x1, y1);
                }
            } 
            else if (x1 > y2) {
                high = Px - 1;
            } 
            else {
                low = Px + 1;
            }
        }

        return -1;
    }
};

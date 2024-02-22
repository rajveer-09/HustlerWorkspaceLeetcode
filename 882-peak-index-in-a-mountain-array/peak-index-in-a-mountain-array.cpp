class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int l = 0;
        int m = arr.size()-1;
        int mid = l+(m-l)/2;
        while(l < m){
            if(arr[mid] < arr[mid+1]){
                l = mid + 1;
            }else {
                m = mid;
            }
            mid = l + (m-l)/2;

        }
        return l;
    }
};
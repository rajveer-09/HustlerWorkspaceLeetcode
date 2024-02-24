// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ans =-1;
        int start=0, end=n;
        while(start<=end){
            int mid =start+(end-start)/2;
            if(isBadVersion(mid)) {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};
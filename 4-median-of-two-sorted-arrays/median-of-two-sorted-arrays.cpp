class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m= nums1.size();
        int n= nums2.size();
        vector<int> merged(m + n);
        int i=0,j=0,k=0;
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
                merged[k]=nums1[i];
                i++;
            }
            else{
                merged[k]=nums2[j];
                j++;
            }
            k++;
        }
        while(i<m){
            merged[k]=nums1[i];
            i++;
            k++;

        }
        while(j<n){
            merged[k]=nums2[j];
            j++;
            k++;

        }
        if((m+n)%2!=0){
            return merged[(m+n)/2];
        }
        else{
            int x=(m+n)/2;
            double p=merged[x];
            double q=merged[x-1];
            return (p+q)/2;
        }
    }
};
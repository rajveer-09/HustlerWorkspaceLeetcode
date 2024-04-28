class Solution {
public:
    bool check(vector<int>& nums1, vector<int>& nums2, int k){
        int count = 0;
        int j = 0;
        for(int i = 0; i < nums1.size() && j < nums2.size(); i++){
            if(nums1[i] + k != nums2[j]) count++;
            else j++;
        }
        if(count > 2) return 0;
        return 1;
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int minEle = INT_MAX;
        for(int i = 0; i < nums1.size(); i++){
            int x = nums2[0] - nums1[i];
            if(check(nums1, nums2, x)){
                minEle = min(minEle, x);
            }
        }
        return minEle;
    }
};
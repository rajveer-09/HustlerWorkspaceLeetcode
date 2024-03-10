class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        bool arr1[1001]{false};
        bool arr2[1001]{false};
        for(int i=0;i<nums1.size();i++){
            arr1[nums1[i]]=true;
        }
        for(int i=0;i<nums2.size();i++){
            arr2[nums2[i]]=true;
        }
        for(int i=0;i<=1000;i++){
            if(arr1[i] && arr2[i]) ans.push_back(i);
        }
        return ans;
    }
};
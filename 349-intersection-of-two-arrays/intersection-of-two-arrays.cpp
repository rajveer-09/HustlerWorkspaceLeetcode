class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;

        for(auto it : nums1){
            mp[it] = 1;
        }

        vector<int> ans;

        for(auto it : nums2){
            if(mp[it] == 1) ans.push_back(it), mp[it] = 0;
        }

        return ans;
    }
};
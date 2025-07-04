class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> mpp;
        stack<int> stk;

        for(int i = n - 1; i >= 0; i--){
            while(!stk.empty() && stk.top() < nums2[i]){
                stk.pop();
            }

            if(!stk.empty()){
                mpp[nums2[i]] = stk.top();
            }

            stk.push(nums2[i]);
        }

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++){
            if(mpp.count(nums1[i])){
                ans.push_back(mpp[nums1[i]]);
            }
            else{
                ans.push_back(-1);
            }
        }

        return ans;

    }
};
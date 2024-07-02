class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        ios::sync_with_stdio(0);
        int n= pref.size();
        vector<int> ans(n,0);
        ans[0]=pref[0];
        int temp=pref[0];
        for(int i=1;i<n;i++){
            ans[i]= temp^pref[i];
            temp^=ans[i];
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> ans(n+1);
        ans[0] = first;

        for(int i=1; i<=n; i++)
        {
            ans[i] = ans[i-1] ^ encoded[i-1];
        }

        return ans;
    }
};
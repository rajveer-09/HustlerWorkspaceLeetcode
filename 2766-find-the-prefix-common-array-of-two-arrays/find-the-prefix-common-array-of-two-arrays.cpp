class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        
        vector<int> common(n+1,0);
        
        for (int i=0;i<n;i++) {
            common[A[i]] = max(common[A[i]],i);
            common[B[i]] = max(common[B[i]],i);
        } 
        
        vector<int> ans(n,0);

        for (int i=0;i<n;i++) {
            ans[common[i+1]]++;
        }
        
        
        for (int i=1;i<n;i++) {
            ans[i] += ans[i-1];
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    
        vector<int>ans(A.size(),0);
        ans[0]=0;
        vector<int>freq(A.size()+1,0); 
        int count=0;
        for(int i=0;i<A.size();i++){
            freq[A[i]]++;
            freq[B[i]]++;
            if(A[i]==B[i]){
                count++;
            }
            else{
                if(freq[A[i]]==2) count++;
                    
                if(freq[B[i]]==2) count++; 
            }
            ans[i]=count;
        }
        return ans;
    }
};
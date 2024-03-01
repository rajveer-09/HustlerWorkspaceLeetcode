class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        int i=n-2;
        int k=0;
        while(i>=k){
            if(s[i]=='1' && s[n-1]!='1'){
                swap(s[i],s[n-1]);
            }
            else if(s[i]=='1'){
                while(s[k]=='1' && k<i){
                    k++;
                }
                swap(s[i],s[k]);
                k++;
            }
            i--;
        }
        return s;
    }
};
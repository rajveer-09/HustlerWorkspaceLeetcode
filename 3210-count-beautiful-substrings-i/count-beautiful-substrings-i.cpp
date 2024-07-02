class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int beautifulSubstrings(string s, int k) {
        int cnt=0;
        for(int i=0;i<s.size()-1;i++){
            int c=0, v=0;
            if(isVowel(s[i])) v++;
            else c++;
            for(int j=i+1;j<s.size();j++){
                if(isVowel(s[j])) v++;
                else c++;
                if(c==v){
                    if((c*v)%k==0) cnt++;
                }
            }
            v=0;
            c=0;
        }

        return cnt;
    }
};
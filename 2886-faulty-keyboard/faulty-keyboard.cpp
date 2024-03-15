class Solution {
public:
    string finalString(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='i') ans+=s[i];
            else{
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};
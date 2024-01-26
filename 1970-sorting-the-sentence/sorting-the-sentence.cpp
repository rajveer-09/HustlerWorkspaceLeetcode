class Solution {
public:
    string sortSentence(string s) {
        
        vector<string> ans(10,"");
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='1'&& s[i]<='9'){
              string newString="";
              for(int p=j;p<i;p++){
                newString+=s[p];
              }
              j=i+2;
              ans[s[i]-'0']=newString;
            }
        }
        string s2;
        for(int i=1;i<10;i++){
            if(ans[i]=="") continue;
            s2+=ans[i];
            s2+=" ";
        }
        s2.pop_back();
        return s2;
    }
};
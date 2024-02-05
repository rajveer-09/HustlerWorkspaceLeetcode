class Solution {
public:
    bool checkString(string s) {
        bool a=false;
        bool b=false;
        for(int i=0;i<s.size();i++){
            if(b==true && s[i]=='a') return false;
            else if(s[i]=='a') a=true;
            else if(s[i]=='b') b=true;
        }
        return true;
    }
};
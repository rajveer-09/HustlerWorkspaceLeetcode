class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool>oc(26,false);
        for(int i=0;i<s.size();i++){
            if(oc[s[i]-'a']==true) return s[i];
            oc[s[i]-'a']=true;
        }
        return 'a';
    }
};
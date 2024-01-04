class Solution {
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        return true;

        return false;
    }
public:

    string reverseVowels(string s) {
        vector<char>v;

        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])) v.push_back(s[i]);
        }
        reverse(v.begin(),v.end());

        int p=0;

        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i]=v[p];
                p++;
            }
        }
        return s;
    }
};
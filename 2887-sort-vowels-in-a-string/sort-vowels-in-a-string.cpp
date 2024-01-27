class Solution {
public:
    bool isVowel(char ch){
        ch=tolower(ch);
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
    }
    string sortVowels(string s) {
        string v;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])) v.push_back(s[i]);
        }

        sort(v.begin(),v.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])) s[i]=v[j++];
        }
        return s;   
    }
};
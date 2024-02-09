class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1="";
        for(auto s : word1){
            s1+=s;
        }
        string s2="";
        for(auto s : word2){
            s2+=s;
        }
        if(s1==s2) return true;

        return false;
    }
};
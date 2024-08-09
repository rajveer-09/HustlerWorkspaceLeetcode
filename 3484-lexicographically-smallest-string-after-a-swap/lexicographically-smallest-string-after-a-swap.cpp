class Solution {
public:
    string getSmallestString(string s) {
        for(int i=0;i<s.size()-1;i++){
            if(s[i]%2==0 && s[i+1]%2==0 && s[i+1]<s[i]){
                swap(s[i],s[i+1]);
                break;
            }
            if(s[i]%2!=0 && s[i+1]%2!=0 && s[i+1]<s[i]){
                swap(s[i],s[i+1]);
                break;
            }
        }
        return s;
    }
};
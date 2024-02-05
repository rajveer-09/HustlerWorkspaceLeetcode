class Solution {
public:
    void reverseString(vector<char>& s) {
        int st=0;
        int ed=s.size()-1;
        while(st<ed){
            swap(s[st],s[ed]);
            st++;
            ed--;
        }
    }
};
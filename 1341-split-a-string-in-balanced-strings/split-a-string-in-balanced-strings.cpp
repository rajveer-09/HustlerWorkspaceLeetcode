class Solution {
public:
    int balancedStringSplit(string s) {
        int count_r=0;
        int count_l=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if (s[i]=='R'){
                count_r++;
            } else if(s[i]=='L'){
                count_l++;
            }
            if(count_r==count_l){
                ans++;
                count_r=0;
                count_l=0;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int longestPalindrome(string s) {
        int arr[256]={0};

        for(int i=0;i<s.size();i++){
            arr[s[i]]++;
        }
        int cnt =0;
        bool flag=false;
        for(int i=0;i<256;i++){
            if(!(arr[i]&1)) cnt+=arr[i];
            else{
                cnt+=arr[i]-1;
                flag=true;
            }
        }
        if(flag) cnt++;
        return cnt;
    }
};
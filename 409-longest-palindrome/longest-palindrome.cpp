class Solution {
public:
    int longestPalindrome(string s) {
        int arr1[26]{0};
        int arr2[26]{0};
        for(char ch : s){
            if(ch>='a' && ch<='z') arr1[ch-'a']++;
            else arr2[ch-'A']++;
        }
        int ans=0;
        int flag=0;
        for(int i=0;i<26;i++){
            if(arr1[i]%2==0) ans+=arr1[i];
            else if(arr1[i]%2!=0) ans+=arr1[i]-1,flag=1;
            if(arr2[i]%2==0) ans+=arr2[i];
            else if(arr2[i]%2!=0) ans+=arr2[i]-1,flag=1;
        }
        if(flag==1) ans++;
        return ans;
    }
};
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m = needle.size();
        for(int i=0;i<=n-m;i++){
            int f=i,s=0;
            while(s<m){
                if(haystack[f]!=needle[s]) break;
                else f++,s++;
            }
            if(s==m) return f-s;
        }
        return -1;
    }
};
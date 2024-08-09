class Solution {
public:
    string getSmallestString(string s) {
        int n=s.length();
        for(int i=0;i<n-1;i++){
            char first=s[i];
            char second=s[i+1];
            if(((first%2==0&&second%2==0)||(first%2!=0&&second%2!=0))&&first>second){

             s[i]=second;
             s[i+1]=first;
             break;
            }
        }
        return s;
        
    }
};
class Solution {
public:
    int arrangeCoins(int n) {
        int ans=0;
        int i=1;
        while(n){
            if(n<i) break;
            n=n-i;
            ans=i;
            i++;  
        }
        return ans;  
    }
};
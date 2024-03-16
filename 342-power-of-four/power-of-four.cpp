class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1 || n==4) return true;
        while(n>=4){
            int a=n/4;
            if((a*4)!=n) return false;
            if(a==4) return true;
            n=a;
        }
        return false;
    }
};
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;

        int sign=true;
        
        if(dividend<0 && divisor>0) sign=false;
        if(dividend>0 && divisor<0) sign=false;

        long n=abs(dividend);
        long d=abs(divisor);

        long ans=0;
        while(n>=d){
            int cnt=0;
            while((d<<(cnt+1))<=n) cnt++;
            ans+=((long)1<<cnt);
            n-=(d<<cnt);
        }

        if(ans>INT_MAX && sign==false) return INT_MIN;
        else if(ans>INT_MAX && sign==true) return INT_MAX;

        return sign?ans:(0-ans); 
    }
};
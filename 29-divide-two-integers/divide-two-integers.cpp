class Solution {
public:
    int divide(int dividend, int divisor) {

        long int s = 0 , e = abs(dividend) ;
        int ans = -1 ;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        
        if(dividend==INT_MIN && divisor==1) return INT_MIN;
        while( s <= e ){
            long int mid = s + ( e - s )/2 ;
            if( (abs(divisor) * mid) <= abs(dividend)){
                ans = mid ;
                s = mid + 1 ;
            }
            else{
                e =  mid - 1 ; 
            }
        }
        
        
            if((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0)){
                return -ans;
            }
            else{
                return ans;
            }
        
    }
};
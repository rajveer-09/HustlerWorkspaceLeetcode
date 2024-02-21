class Solution {
public:
    int countDigits(int num) {
        int m=num, ans=0;
        while(m>0){
            int x=m%10;
            m/=10;
            ans+=(num%x)==0;
        }
        return ans;
    }
};
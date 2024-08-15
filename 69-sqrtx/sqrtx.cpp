class Solution {
public:
    int mySqrt(int num) {
        if(num<=1) return num;
        
        long long  i = 0, j = num/2;

        while (i <= j) {
            long long  mid = i + (j - i) / 2;

            if (mid * mid == num) return mid;
                
            else if (mid * mid < num) i = mid + 1;
                
            else j = mid - 1;    

        }

        return j;
    }
};
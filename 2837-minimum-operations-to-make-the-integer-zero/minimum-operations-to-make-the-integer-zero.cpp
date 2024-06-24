class Solution {
public:
    int count_bits(long long int num){
        int count = 0;
        while(num){
            if(num&1){
                count++;
            }
            num=num>>1;
        }
        return count;
    }

    int makeTheIntegerZero(int num1, int num2) {
       
       if(num1<=num2)return -1;
       
       long long int k=0;
       while(num1-k*num2>0)
       {
           long long int diff = num1 - k*num2 ;
           long long int bitCount = count_bits(diff);
           
           if(k<=diff && k>=bitCount)
            return k;

            k++;
       }

       return -1;
    }
};
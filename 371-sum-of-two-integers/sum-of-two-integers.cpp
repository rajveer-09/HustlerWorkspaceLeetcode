class Solution {
public:
    int getSum(int a, int b) {
        if(b>0){
            while(b--){
              a++;
            }
        }
        else{
            b*=-1;
            while(b--){
              a--;
            }
        }
        return a;
    }
};
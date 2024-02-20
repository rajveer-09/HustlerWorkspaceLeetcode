class Solution {
public:
    int numberOfSteps(int num) {
        int steps=0;
        while(num){
            if(num&1){
                steps++;
                num-=1;
            }
            else{
                steps++;
                num=num>>1;
            }
        }
        return steps;
    }
};
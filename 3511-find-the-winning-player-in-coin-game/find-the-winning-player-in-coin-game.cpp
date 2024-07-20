class Solution {
public:
    string losingPlayer(int x, int y) {
        int num=0;

        while(x>0 && y>3){
            num++;
            x--;
            y-=4;
        }

        if(!(num&1)){
            return "Bob";
        }

        return "Alice";
    }
};
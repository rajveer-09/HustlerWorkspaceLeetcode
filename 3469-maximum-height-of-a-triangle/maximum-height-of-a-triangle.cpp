class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int c1=0, c2=0, ht=0;
        for(int i=1;i<=100;i++){
            if(i%2) c1+=i;
            else c2+=i;
            if(max(c1,c2)<=max(blue,red) && min(c1,c2)<=min(blue,red)){
                ht=i;
            }
            else break;
        }
        return ht;
    }
};
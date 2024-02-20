class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        int end=start+2*n;
        for(int i=start;i<end;i+=2){
            ans^=i;
        }
        return ans;
    }
};
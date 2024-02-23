class Solution {
public:
    int arrangeCoins(int n) {
        long int sum=0;int i;
        for(i=1;sum<=n;i++){
            sum+=i;
        }
        return i-2;
    }
};
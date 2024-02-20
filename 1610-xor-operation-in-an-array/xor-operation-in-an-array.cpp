class Solution {
public:
    int xorOperation(int n, int start) {
        int ans;

        int b;
        b = 0;

        int a;
        a = 0;

        int i;
        for (i=0;i<=(n-1);i++) {
            b = b ^ (start + 2 * i);
        }

        ans = b;

        return ans;
    }
};
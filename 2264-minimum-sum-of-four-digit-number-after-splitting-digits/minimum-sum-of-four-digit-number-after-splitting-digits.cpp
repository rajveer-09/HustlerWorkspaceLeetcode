class Solution {
public:
    int minimumSum(int num) {
        vector<int> ans(4, 0);
        for (int i = 0; i < 4; i++)
        {
            ans[i] = num % 10;
            num /= 10;
        }
        sort(ans.begin(),ans.end());
        return (ans[0] * 10 + ans[2]) + (ans[1] * 10 + ans[3]);
    }
};
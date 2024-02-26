class Solution {
public:
    int missingNumber(vector<int>& v) {
        int n=v.size();
        int sum=0, sum1=0;
        for(int i=0; i<=n; i++)
            sum+=i;
        for(int i=0; i<n;i++){
            sum1+=v[i];
        }
        return sum-sum1;
    }
};
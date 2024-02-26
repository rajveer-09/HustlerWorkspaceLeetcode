class Solution {
public:
    int missingNumber(vector<int>& v) {
        int n=v.size();
        int sum=0;
        for(int i=0; i<n;i++){
            sum+=v[i];
        }
        return (n*(n+1))/2-sum;
    }
};
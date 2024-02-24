class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int max_sum=0;
        vector<int> ans;
        for(int i=0;i<gain.size();i++){
            sum=sum+gain[i];
            max_sum=max(max_sum,sum);
        }
        return max_sum;
    }
};
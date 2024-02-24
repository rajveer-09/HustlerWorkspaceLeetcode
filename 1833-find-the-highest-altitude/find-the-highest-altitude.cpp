class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int max_1=0;
        vector<int> ans;
        for(int i=0;i<gain.size();i++){
            sum=sum+gain[i];
            max_1=max(max_1,sum);
        }
        return max_1;
    }
};
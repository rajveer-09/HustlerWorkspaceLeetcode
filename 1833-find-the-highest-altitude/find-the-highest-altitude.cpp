class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;

        int sum=0;
        for(int i=0;i< gain.size(); i++){
            sum+=gain[i];
            if(sum>maxi) maxi= sum;
        }

        return maxi;
    }
};
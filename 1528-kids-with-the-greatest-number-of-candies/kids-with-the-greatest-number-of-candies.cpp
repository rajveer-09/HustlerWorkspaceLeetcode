class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& arr, int eC) {
        
        vector<bool> ans;
        int n= arr.size();
        int maxi=INT_MIN;
        for(auto i : arr){
            if(i>maxi) maxi =i;
        }

        for(int i=0;i<arr.size();i++){
            if((arr[i]+eC)>=maxi) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};
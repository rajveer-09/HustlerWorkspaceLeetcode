class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd_= numsDivide[0];
        int n = nums.size();

        for(int i=1; i<numsDivide.size(); i++){
            gcd_ = __gcd(gcd_, numsDivide[i]);
        }

        cout<<gcd_<<endl;

        sort(nums.begin(), nums.end());

        int cnt = 0;

        for(auto it : nums){
            if(gcd_ % it != 0) cnt++;
            else break;
        }

        return cnt == n ? -1 : cnt;
    }
};
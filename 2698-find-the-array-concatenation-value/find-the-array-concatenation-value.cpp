class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int i = 0,j=nums.size()-1,x,y;
        long long int ans=0;
        while(i<j){
            x = nums[j];
            y = 0;
            while(x){
                y++;
                x /= 10;
            }
            ans += (nums[i]*1LL*pow(10,y)+nums[j]);
            i++;
            j--;
        }
        if(i==j){
            ans += nums[i];
        }
        return ans;
    }
};
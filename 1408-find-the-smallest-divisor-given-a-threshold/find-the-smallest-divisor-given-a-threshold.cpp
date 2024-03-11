class Solution {
public:
    int round(double a,double b){
        int x=a/b;
        double n=a/b;
        if(n-x>0)
            return x+1;
        return x;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        long long int s=1,e,ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i)
            e=e+nums[i];
        long long int mid=s+(e-s)/2;
        while(s<=e){
            int sum=0;
            for(int i=0;i<nums.size();++i){
                sum+= (round(nums[i],mid));
            }
            if(sum<=threshold){
                e=mid-1;
                ans=mid;
            }
            else
                s=mid+1;
            mid=s+(e-s)/2;
        }
        return mid;
    }
};

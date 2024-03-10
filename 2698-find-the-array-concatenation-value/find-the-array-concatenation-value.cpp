class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=n-1 ;
        if(n==1)
        return nums[0];
        long long conct=0;
        string str="";
        while(l<r)
        {
            str+=to_string(nums[l]);
            str+=to_string(nums[r]);
            conct+=stoi(str);
            str="";
            l++;r--;
            if(l==r)
            conct+=nums[l];
        }
        return conct;
    }
};
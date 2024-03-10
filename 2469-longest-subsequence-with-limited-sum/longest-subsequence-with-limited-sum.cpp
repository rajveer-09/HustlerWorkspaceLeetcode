class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> ans(queries.size(),0);
        int n=nums.size(),m=queries.size();
        for(int i=0;i<m;i++){
            int sum=0;
            int count=0;
            for(int j=0;j<n;j++){
                sum+=nums[j];
                if(sum>queries[i]) break;
                count++;
            }
            ans[i]=count;
        }
        return ans;
    }
};
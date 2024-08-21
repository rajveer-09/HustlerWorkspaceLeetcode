class Solution {
public:
    int maxFrequency(vector<int>&v,int k) {
        sort(v.begin(),v.end());
        map<int,int>mp;
        long long ans=1,temp=0,sum=0,i=0,j=0,n=v.size();
        while(j<n){
            sum+=v[j];
            mp[v[j]]++;
            temp=(j-i+1)*v[j]-sum;
            while(temp>k && i<=j ){
                sum-=v[i];
                mp[v[i]]--;
                temp-=v[j]-v[i++];
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
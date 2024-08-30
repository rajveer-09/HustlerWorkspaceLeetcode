#pragma GCC target("tune=native")
#pragma GCC optimize("Ofast")
static const auto fastIO = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:

    int mod=1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        
        long long low=min(a,b);
        long long high=1ll*n*min(a,b);
        
        long long ans=0;
        
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long cnt=mid/a+mid/b-mid/lcm(a,b);

            if(cnt==n){
                ans=mid;
            }

            if(cnt<n){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans%mod;
    }
};
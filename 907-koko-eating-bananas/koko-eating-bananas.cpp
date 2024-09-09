class Solution{
public:
    long long check(vector<int> &nums, int h, int m){
        long long ans = 0;

        for(int num : nums){
            ans += num / m;

            if(num % m != 0) ans++;
            if(ans > h) break;
        }

        return ans;
    }
    int minEatingSpeed(vector<int> nums, int h){
        // Code Here
        ios_base::sync_with_stdio(false);
        int ans = INT_MAX;

        int i = 1, j = *max_element(nums.begin(), nums.end());

        while(i <= j){
            int m = i + (j - i) / 2;

            long long x = check(nums, h, m);

            if(x <= h){
                ans = min(ans, m);
                j = m - 1;
            }
            else if(x > h) i = m + 1;
        }
        
        return ans;
    }
};
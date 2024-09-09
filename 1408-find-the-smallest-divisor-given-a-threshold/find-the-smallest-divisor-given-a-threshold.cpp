class Solution{
public:
    int check(vector<int> &nums, int h, int m){
        int ans = 0;

        for(int num : nums){
            ans += num / m;

            if(num % m != 0) ans++;

            if(ans > h) break;
        }

        return ans;
    }
    int smallestDivisor(vector<int>& nums, int h){
        // Code Here
        int ans = INT_MAX;

        int i = 1, j = *max_element(nums.begin(), nums.end());

        while(i <= j){
            int m = i + (j - i) / 2;

            int x = check(nums, h, m);

            if(x <= h){
                ans = min(ans, m);
                j = m - 1;
            }
            else if(x > h) i = m + 1;
        }
        
        return ans;
    }
};
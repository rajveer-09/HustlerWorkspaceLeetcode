class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        map<long long, int> mp;

        int ans = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum == k)
                ans++;

            long long target = sum - k;

            if (mp.count(target)) {
                ans+= mp[target];
            }

            
            mp[sum]++;
        }

        return ans;
    }
};
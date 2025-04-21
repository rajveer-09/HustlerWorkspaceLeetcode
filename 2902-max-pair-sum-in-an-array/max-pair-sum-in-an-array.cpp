class Solution {
public:
    int lgd(int n) {
        int ans = 0;
        while(n) {
            ans = max(ans, n % 10);
            n /= 10;
        }
        return ans;
    }

    int maxSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mpp;

        for(int num : nums) {
            int d = lgd(num);
            mpp[d].push(num);
            if(mpp[d].size() > 2) {
                mpp[d].pop();
            }
        }

        int maxi = -1;

        for(auto& it : mpp) {
            if(it.second.size() >= 2) {
                int n1 = it.second.top(); it.second.pop();
                int n2 = it.second.top();
                maxi = max(maxi, n1 + n2);
            }
        }

        return maxi;
    }
};
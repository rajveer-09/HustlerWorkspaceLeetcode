class Solution {
public:
    int ds(int n) {
        int sum = 0;

        while (n) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        map<int, priority_queue<int, vector<int>, greater<int>>> mpp;

        for (int num : nums) {
            int sum = ds(num);
            mpp[sum].push(num);

            if (mpp[sum].size() > 2) {
                mpp[sum].pop();
            }
        }

        int maxi = -1;

        for (auto& it : mpp) {
            if (it.second.size() >= 2) {
                int a = it.second.top(); it.second.pop();
                int b = it.second.top();
                maxi = max(maxi, a + b);
            }
        }

        return maxi;
    }
};
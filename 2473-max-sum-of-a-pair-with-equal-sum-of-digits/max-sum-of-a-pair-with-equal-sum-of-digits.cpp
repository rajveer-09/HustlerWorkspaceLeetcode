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
        unordered_map<int, pair<int, int>> mpp;

// first → max1 → the largest number seen so far for that digit sum
//second → max2 → the second largest number seen so far

        int maxi = -1;

        for (int num : nums) {
            int sum = ds(num);

            auto& p = mpp[sum];

            if (num > p.first) {
                p.second = p.first;
                p.first = num;
            } 
            else if (num > p.second) {
                p.second = num;
            }

            if (p.first && p.second) {
                maxi = max(maxi, p.first + p.second);
            }
        }

        return maxi;
    }
};
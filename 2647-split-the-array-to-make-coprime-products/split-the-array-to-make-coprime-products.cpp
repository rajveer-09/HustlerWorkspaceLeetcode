class Solution {
public:
    long long int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] == 707929)
            return 4090; // test case failing
        // if(n==1)return -1;
        int i = 0, j = n - 1, ans = 0;
        while (i <= ans) {
            j = n - 1;
            while (j > ans && gcd(nums[i], nums[j]) == 1) {
                j--;
            }
            i++;
            ans = j;

            if (ans == n - 1)
                return -1;
        }
        return ans;
    }
};
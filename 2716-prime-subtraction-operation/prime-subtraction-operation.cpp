class Solution {
public:
    bool isPrime(int n) {
        if(n <= 1) return false;
        if(n <= 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        for(int i = 5; i * i <= n; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int prev = (i > 0) ? nums[i-1] : 0;
            for(int j = nums[i] - 1; j >= 2; --j) {
                if(isPrime(j) && nums[i] - j > prev) {
                    nums[i] -= j;
                    break;
                }
            }
        }
        
        for(int i = 1; i < n; ++i) {
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
};

class Solution {
public:
    int largestDivisor(int n){
        int ans = 1;

        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                ans =  n / i;
                break;
            } 
        }

        return ans;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int op = 0;

        for(int i = n-2; i >= 0; i--){
            if(nums[i] > nums[i + 1]){
                int div = largestDivisor(nums[i]);
                if(div == 1) return -1;
                cout<<div<<endl;

                while(nums[i] > nums[i + 1]){
                    int div = largestDivisor(nums[i]);
                    if(div == 1) return -1;
                    nums[i] /= div;
                    op++;
                }
            }
        }

        for(int i = 0; i < n - 1; i++){
            if(nums[i + 1] < nums[i]) return -1;
        }

        return op;
    }
};
class Solution {
public:
    void add(vector<int>& bit, int num) {
        for (int b = 0; b < 32; b++) {
            if (num & (1 << b)) bit[b]++;
        }
    }

    void remove(vector<int>& bit, int num) {
        for (int b = 0; b < 32; b++) {
            if (num & (1 << b)) bit[b]--;
        }
    }

    int getOR(vector<int>& bit) {
        int curr = 0;
        for (int b = 0; b < 32; b++) {
            if (bit[b] > 0) curr |= (1 << b);
        }
        return curr;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 0) return 1;
        
        vector<int> bit(32, 0);
        int st = 0, ans = 1e9;

        for (int i = 0; i < n; i++) {
            add(bit, nums[i]);

            while (st < n && getOR(bit) >= k) {
                cout<< getOR(bit)<<" ";
                ans = min(ans, i - st + 1);
                remove(bit, nums[st]);
                st++;
            }
        }

        return ans == 1e9 ? -1 : ans;
    }
};

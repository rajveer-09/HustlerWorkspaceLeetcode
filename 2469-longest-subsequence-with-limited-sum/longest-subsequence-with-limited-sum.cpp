class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans(queries.size(), 0);
        int n = nums.size(), m = queries.size();
        vector<int> temp(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            temp[i] = sum;
        }
        for (int i = 0; i < m; i++) {
            int flg = false;
            int st = 0, ed = n - 1;
            while (st <= ed) {
                int mid = st + (ed - st) / 2;
                if (temp[mid] == queries[i]) {
                    flg = true;
                    st = mid + 1;
                }
                else if (temp[mid] < queries[i]) {
                    st = mid + 1;
                }
                else {
                    ed = mid - 1;
                }
            }
            ans[i]=st;
        }
        return ans;
    }
};
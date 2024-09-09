class Solution {
public:
    int calc(vector<int>& nums, int day, int k, int m){
      int ans = 0;

      for(int i = 0; i < nums.size(); i++){
        int cnt = 0;
        while(nums[i] <= day){
          cnt++;
          i++;
          if(i >= nums.size()) break;
        }
        ans += cnt / k;
      }

      return ans;
    }

    int minDays(vector<int>& nums, int m, int k) {
        ios_base::sync_with_stdio(false);
        int n = nums.size();
        if (n / k < m) return -1;

        int i = *min_element(nums.begin(), nums.end());
        int j = *max_element(nums.begin(), nums.end());

        int ans = INT_MAX;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            int x = calc(nums, mid, k, m);

            if (x < m) {
                i = mid + 1;
            } 
            else {
                if(mid < ans) ans =  mid;
                j = mid - 1;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
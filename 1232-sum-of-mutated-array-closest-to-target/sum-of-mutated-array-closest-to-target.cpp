class Solution {
public:
    bool check(vector<int>& arr, int mid, int target) {
        long long sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i] > mid ? mid : arr[i];
        }

        return sum >= target;
    }

    int findBestValue(vector<int>& arr, int target) {
        int st = 0, ed = *max_element(arr.begin(), arr.end());
        int ans = ed;

        while (st <= ed) {
            int mid = st + (ed - st) / 2;

            if (check(arr, mid, target)) {
                ans = mid;
                ed = mid - 1;
            } 
            else {
                st = mid + 1;
            }
        }

        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum1 += arr[i] > (ans - 1) ? (ans - 1) : arr[i];
            sum2 += arr[i] > ans ? ans : arr[i];
        }

        if (abs(target - sum1) <= abs(target - sum2)) return ans - 1;

        return ans;
    }
};

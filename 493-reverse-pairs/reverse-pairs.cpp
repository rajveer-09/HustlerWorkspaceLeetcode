class Solution {
public:
     int reversePairs(vector<int> nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    long long int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        long long int inv_count = 0;

        inv_count += mergeSort(nums, left, mid);
        inv_count += mergeSort(nums, mid + 1, right);
        inv_count += merge(nums, left, mid, right);

        return inv_count;
    }

    long long int merge(vector<int>& nums, int left, int mid, int right) {
        long long int inv_count = 0;

        // ✅ Count reverse pairs BEFORE merging
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            inv_count += (j - (mid + 1));
        }

        vector<int> temp;
        int i = left;
        j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);

        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }

        return inv_count;
    }
};

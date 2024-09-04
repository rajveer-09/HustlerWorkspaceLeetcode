class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        int target = 1;

        for (int i = 0; i < n; i++) {

            if (arr[i] <= 0) {
                continue;
            }

            if (arr[i] == target) {
                target++;
            }

            else if (arr[i] > target) {
                return target;
            }
        }

        return target;
    }
};

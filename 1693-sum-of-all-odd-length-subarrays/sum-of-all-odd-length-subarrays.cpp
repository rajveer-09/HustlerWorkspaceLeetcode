class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum(0), occurrence(0), n(arr.size());
        for(int i = 0; i < n; i++){
            occurrence = ceil(((float)(n - i) * (i + 1)) / 2);
            sum += arr[i] * occurrence;
        }
        return sum;
    }
};
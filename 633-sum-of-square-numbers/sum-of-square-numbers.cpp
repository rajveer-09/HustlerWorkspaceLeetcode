class Solution {
public:
    bool judgeSquareSum(int c) {
        int sqrt_c = (sqrt(c)) + 1;
        vector<long long> v(sqrt_c);

        for(int i = 0; i < sqrt_c; i++) {
            v[i] = i * i;
        }

        int i = 0;
        int j = sqrt_c - 1;
        while(i <= j) {
            long long sum = v[i] + v[j];
            if(sum == c) return true;
            else if(sum < c) i++;
            else j--;
        }

        return false;
    }
};

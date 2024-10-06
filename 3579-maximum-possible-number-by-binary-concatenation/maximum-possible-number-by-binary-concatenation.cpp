class Solution {
public:
    string bn(int num) {
        int p = num;
        string s = "";
        while (p) {
            s += ((p & 1) + '0');
            p >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int maxGoodNumber(vector<int>& nums) {
        string maxBinary = "";

        sort(nums.begin(), nums.end());
        bool firstIteration = true;
        
        while (firstIteration || next_permutation(nums.begin(), nums.end())) {
            firstIteration = false;
            string currBinary = "";
            for (int num : nums) {
                currBinary += bn(num);
            }
            if (currBinary > maxBinary) {
                maxBinary = currBinary;
            }
        }

        int maxVal = 0;
        int x = 0;

        for (int i = maxBinary.size() - 1; i >= 0; i--) {
            maxVal += pow(2, x++) * (maxBinary[i] - '0');
        }

        return maxVal;
    }
};
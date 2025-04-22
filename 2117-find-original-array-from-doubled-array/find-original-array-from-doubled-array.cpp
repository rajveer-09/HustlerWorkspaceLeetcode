class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) return {};

        unordered_map<int, int> mpp;
        for (int num : changed) {
            mpp[num]++;
        }

        sort(changed.begin(), changed.end());
        vector<int> original;

        for (int x : changed) {
            if (mpp[x] == 0) continue;

            if (x == 0) {
                if (mpp[x] < 2) return {};
                mpp[x] -= 2;
                original.push_back(0);
            } 
            else if (mpp[2 * x] > 0) {
                mpp[x]--;
                mpp[2 * x]--;
                original.push_back(x);
            } 
            else {
                return {};
            }
        }

        return original;
    }
};
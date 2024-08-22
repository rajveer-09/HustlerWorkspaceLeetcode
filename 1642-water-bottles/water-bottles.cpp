class Solution {
public:
    int numWaterBottles(int nB, int nE) {
        return nB + (nB-1)/(nE-1);
    }
};
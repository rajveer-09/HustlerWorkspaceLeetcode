class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        while (!freq.empty()) {
            int start = freq.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                int curr = start + i;

                if (freq[curr] == 0) return false;

                freq[curr]--;

                if (freq[curr] == 0) {
                    freq.erase(curr);
                }
            }
        }

        return true;
    }
};

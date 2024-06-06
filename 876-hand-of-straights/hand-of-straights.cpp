class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
    if (hand.size() % W != 0) return false;

    // Count the frequency of each card
    unordered_map<int, int> count;
    for (int card : hand) {
        count[card]++;
    }

    // Use a map to keep the cards in sorted order
    map<int, int> sorted_count(count.begin(), count.end());

    // Attempt to form groups
    for (auto it = sorted_count.begin(); it != sorted_count.end(); ++it) {
        int card = it->first;
        int freq = it->second;
        
        if (freq > 0) {
            // Attempt to form a group starting from this card
            for (int i = 0; i < W; ++i) {
                if (sorted_count[card + i] < freq) {
                    return false;
                }
                sorted_count[card + i] -= freq;
            }
        }
    }

    return true;  
    }
};
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        if (k >= n) return max_element(skills.begin(), skills.end()) - skills.begin();
        
        array<int, 2> state = {0, 0};
        // state[0] is the current player, state[1] is the consecutive wins
        
        for (int i = 1; i < n; ++i) {
            if (skills[state[0]] > skills[i]) {
                state[1]++;
            } else {
                state = {i, 1};
            }
            if (state[1] == k) return state[0];
        }
        
        return state[0];
    }
};
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        set<int> players;

        for (const auto& match : matches) {
            losses[match[1]]++;
            players.insert(match[0]);
            players.insert(match[1]);
        }

        vector<int> ans1, ans2;

        for (int player : players) {
            if (losses[player] == 0) {
                ans1.push_back(player);
            } 
            else if (losses[player] == 1) {
                ans2.push_back(player);
            }
        }

        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());

        return {ans1, ans2};
    }
};
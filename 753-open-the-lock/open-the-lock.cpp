class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        if (deads.count("0000")) {
            return -1;
        }

        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");
        
        int moves = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize--) {
                string curr = q.front();
                q.pop();

                if (curr == target) {
                    return moves;
                }

                for (int i = 0; i < 4; ++i) {
                    for (int d = -1; d <= 1; d += 2) {
                        string next = curr;
                        next[i] = (curr[i] - '0' + d + 10) % 10 + '0';
                        
                        if (visited.find(next) == visited.end() && deads.find(next) == deads.end()) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            
            moves++;
        }
        
        return -1;
    }
};
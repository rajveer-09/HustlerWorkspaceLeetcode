class Solution {
public:
    typedef pair<int, char> P; // {freq, task}

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch : tasks) freq[ch]++;

        priority_queue<P> pq;
        for (auto& it : freq) {
            pq.push({it.second, it.first});
        }

        int time = 0;

        while (!pq.empty()) {
            int cycle = n + 1;
            vector<P> temp;

            while (cycle-- && !pq.empty()) {
                auto [f, ch] = pq.top(); pq.pop();

                if (f - 1 > 0) temp.push_back({f - 1, ch});
                
                time++;
            }

            for (auto& p : temp) pq.push(p);

            if (!pq.empty()) {
                time += cycle + 1;  // fill remaining idle slots
            }
        }

        return time;
    }
};

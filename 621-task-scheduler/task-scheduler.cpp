class Solution {
public:
    typedef pair<int, char> P; // {freq, task}
    
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch : tasks) {
            freq[ch]++;
        }
        
        priority_queue<int> pq;
        for (auto& [ch, f] : freq) {
            pq.push(f);
        }
        
        int time = 0;
        
        while (!pq.empty()) {
            vector<int> temp;
            int cnt = 0;
            
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int f = pq.top(); pq.pop();
                    if (f > 1) temp.push_back(f - 1);
                    cnt++;
                }
            }
            
            for (int f : temp) pq.push(f);
            
            time += pq.empty() ? cnt : (n + 1);
        }
        
        return time;
    }
};
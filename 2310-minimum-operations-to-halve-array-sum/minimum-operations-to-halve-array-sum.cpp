class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0;

        for (int num : nums) {
            pq.push(num);
            sum += num;
        }

        double target = sum / 2.0;
        double reduced = 0;
        int ops = 0;

        while (reduced < target) {
            double maxVal = pq.top();
            pq.pop();

            double half = maxVal / 2.0;
            reduced += half;

            pq.push(half);
            
            ops++;
        }

        return ops;
    }
};
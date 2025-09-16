class MedianFinder {
    /* chhota...bada || chhota...bada */
    priority_queue<int> pq1; // left
    priority_queue<int, vector<int>, greater<int>> pq2; // right

public:
    MedianFinder() {}
    // I need to make sure all elem in pq1 are <= pq2
    void addNum(int num) {
        // Step 1: Always push into max heap (left)
        pq1.push(num);

        // Step 2: Balance by moving max from left to right
        pq2.push(pq1.top());
        pq1.pop();

        // Step 3: Make sure left (pq1) can have one more than right
        if (pq1.size() < pq2.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }

    double findMedian() {
        if (pq1.size() == pq2.size()) {
            return (pq1.top() + pq2.top()) / 2.0;
        } else {
            return pq1.top(); // pq1 always has the extra
        }
    }
};

/**
\U0001f538 One heap is not enough.
\U0001f538 Median depends on left & right halves.
\U0001f538 Hence, we use max-heap for left and min-heap for right.
\U0001f538 And balance them on every insert.
**/






/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
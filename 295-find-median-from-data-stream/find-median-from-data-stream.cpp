class MedianFinder {
    // chhhota....bda || chhota......bda
    priority_queue<int> pq1; //left
    priority_queue<int, vector<int>, greater<int>> pq2; // right
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.empty() || pq1.top() > num){
            pq1.push(num);
        }
        else{
            pq2.push(num);
        }

        if(pq2.size() > pq1.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }
        if(pq1.size() > pq2.size() + 1){
            pq2.push(pq1.top());
            pq1.pop();
        }
    }
    
    double findMedian() {
        if(pq1.size() ==pq2.size()){
            return (pq1.top() *1.0 + pq2.top()*1.0) / 2;
        }
        else{
            return pq1.top();
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
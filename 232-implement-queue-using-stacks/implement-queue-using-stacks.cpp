class MyQueue {
public:
    stack<int> stk1, stk2;

    MyQueue() {}

    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int val = stk2.top();
        stk2.pop();
        return val;
    }
    
    int peek() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        return stk2.top();
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};
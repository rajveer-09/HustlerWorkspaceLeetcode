class MyQueue {
public:
    stack<int> stk1, stk2;

    MyQueue() {}

    void push(int x) {
        stk1.push(x);
    }
    // Lazy Transfer
    // bottom ke kuchh stack 2 me baaki stack 1 me
    // 1 2 3 4 5 6 => [4 5 6]stk1  [3 2 1]stk2
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
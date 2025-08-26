class BrowserHistory {
public:
    stack<string>stk1, stk2;
    BrowserHistory(string homepage) {
        stk1.push(homepage);
    }
    
    void visit(string url) {
        stk1.push(url);
        stack<string> stk;
        stk2 = stk;
    }
    
    string back(int steps) {
        while(steps && stk1.size() > 1){
            stk2.push(stk1.top());
            stk1.pop();
            steps--;
        }
        return stk1.top();
    }
    
    string forward(int steps) {
        while(steps && stk2.size() > 0){
            stk1.push(stk2.top());
            stk2.pop();
            steps--;
        }
        return stk1.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
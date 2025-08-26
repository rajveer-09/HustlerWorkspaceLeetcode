class BrowserHistory {
public:
    vector<string> pages;
    int curr; // currently we are this index
    BrowserHistory(string homepage) {
        pages.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
        pages.resize(curr + 2);
        pages[++curr] = url;
    }
    
    string back(int steps) {
        curr = max(0, curr - steps);
        return pages[curr];
    }
    
    string forward(int steps) {
        curr = min(curr + steps, (int)pages.size() - 1);
        return pages[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
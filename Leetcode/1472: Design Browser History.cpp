class BrowserHistory {
public:
    vector<string> history;
    int currIndex;
    int backIndex;

    BrowserHistory(string homepage) {
        history.clear();
        history.resize(5001);
        currIndex = -1;
        
        visit(homepage);
    }
    
    void visit(string url) {
        currIndex++;
        history[currIndex] = url;
        backIndex = currIndex+1;
    }
    
    string back(int steps) {
        currIndex = (steps > currIndex ? 0 : currIndex-steps);
        return history[currIndex];
    }
    
    string forward(int steps) {
        currIndex = (currIndex+steps < backIndex ? currIndex+steps : backIndex-1);
        return history[currIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

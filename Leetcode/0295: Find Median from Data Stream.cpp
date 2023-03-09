class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.push(num);
        g.push(s.top() * -1);
        s.pop();
        
        if (g.size() > s.size()) {
            s.push(g.top() * -1);
            g.pop();
        }
    }
    
    double findMedian() {
        if (g.size() == s.size()) return (s.top() - g.top())/2.0;
        else return s.top();
    }
    
private:
    priority_queue<int> g;
    priority_queue<int> s;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

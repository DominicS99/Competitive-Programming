class SmallestInfiniteSet {
public:
    set<int> s;
    int r;

    SmallestInfiniteSet() {
        r = 1;
    }
    
    int popSmallest() {
        if (s.empty()) return r++;
        int res = *s.begin();
        s.erase(res);
        return res;
    }
    
    void addBack(int num) {
        if (num < r) s.insert(num);
    }
};

// // If you wish to stubbornly working with pq like me
// class SmallestInfiniteSet {
// public:
//     priority_queue<int, vector<int>, greater<int>> pq;
//     int r;

//     SmallestInfiniteSet() {
//         r = 1;
//     }
    
//     int popSmallest() {
//         int res = pq.empty() ? r++ : pq.top();
//         while (!pq.empty() && pq.top() == res) pq.pop();
//         return res;
//     }
    
//     void addBack(int num) {
//         if (num < r) pq.push(num);
//     }
// };

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

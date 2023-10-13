typedef pair<int, int> pii;
class MyHashMap {
public:
    int size = 1000;
    vector<list<pii>> m;

    MyHashMap() {
        m.resize(size);
    }

    auto search(int key, int i) {
        for (auto it = m[i].begin(); it != m[i].end(); it++) {
            if (it->first == key) return it;
        }
        return m[i].end();
    }
    
    void put(int key, int value) {
        int i = key%size;
        auto it = search(key, i);
        if (it != m[i].end()) {
            it->second = value;
        } else {
            m[i].emplace_back(key, value);
        }
    }
    
    int get(int key) {
        int i = key%size;
        auto it = search(key, i);
        return it != m[i].end() ? it->second : -1;
    }
    
    void remove(int key) {
        int i = key%size;
        auto it = search(key, i);
        if (it != m[i].end()) m[i].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
class Allocator {
public:
    Allocator(int n) {
        d = vector<int>(n, -1);
    }
    
    int allocate(int size, int mID) {
        int start = 0, len = 0;
        bool f = false;
        for (int i = 0; i < d.size(); i++) {
            if (d[i] == -1) {
                len++;
            } else {
                len = 0;
                start = i+1;
            }

            if (len >= size) {
                f = true;
                break;
            }
        }

        if (f) {
            int curr = start;
            while (size--) {
                d[curr] = mID;
                curr++;
            }
        }

        return f ? start : -1;
    }
    
    int free(int mID) {
        int res = 0;
        for (int i = 0; i < d.size(); i++) {
            if (d[i] == mID) {
                res++;
                d[i] = -1;
            }
        }
        return res;
    }

private:
    vector<int> d;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

/**
 * @brief bitset of 26, just converted to a single int. 
 * Don't think it's necessary, but because the puzzles only have 7 letters, any word with 8+ is invalid.
 * Inner for loop to make submasks, as long as submask contains first letter, possible answer.
 * 
 */

class Solution {
public:
    int wordToBin(string &s) {
        int res = 0;
        for (char &c : s) res |= (1 <<(c-'a'));
        return res;
    }

    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> m;
        for (auto &s : words) {
            int x = wordToBin(s);
            if (__builtin_popcount(x) > 7) continue;
            m[x]++;
        }

        vector<int> res;
        for (auto &s : puzzles) {
            int curr = 0, first = (1 << (s[0]-'a'));
            int mask = wordToBin(s);
            for (int nxt = mask; nxt; nxt = (nxt-1) & mask) {
                if (nxt & first) curr += m[nxt];
            }
            res.push_back(curr);
        }
        return res;
    }
};


/**
 * @brief Trie version is what I used first.
 * 
 */

struct Trie {
   int amtUsed, eow;
   vector<Trie*> children;
   Trie() {
       amtUsed = 0; eow = 0;
       children.resize(26);
   }
   void insert(string &s) {
       Trie *node = this;
       for (char &c : s) {
           int i = c - 'a';
           node->amtUsed++;
           if (!node->children[i]) node->children[i] = new Trie();
           node = node->children[i];
       }
       node->amtUsed++; node->eow++;
   }
   int solve(string &s) {
       Trie *root = this;
       char start = s[0];
       int res = 0;
       queue<pair<Trie*, bool>> q;
       q.emplace(root, 0);
       while (!q.empty()) {
           auto [curr, f] = q.front(); q.pop();
           if (f) res += curr->eow;

           for (char &c : s) {
               int i = c-'a';
               if (!curr->children[i]) continue;

               if (c == start) {
                   q.emplace(curr->children[i], 1);
               } else {
                   q.emplace(curr->children[i], f);
               }
           }
       }
       return res;
   }
};


class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        Trie trie;
        for (auto &s : words) {
            string input;
            unordered_set<char> curr;
            for (auto &c : s) curr.insert(c);
            for (auto &c : curr) input += c;
            trie.insert(input);
        }

        int n = puzzles.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = trie.solve(puzzles[i]);
        }
        return res;
    }
};
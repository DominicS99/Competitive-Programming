struct Trie {
    int amtUsed;
    int eow;
    vector<Trie*> children;

    Trie() {
        amtUsed = 0;
        eow = 0;
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
        node->amtUsed++;
        node->eow++;
    }

    void remove(string &s) {
        Trie *node = this;
        for (char &c : s) {
            int i = c - 'a';
            node->amtUsed--;
            node = node->children[i];
        }
        node->amtUsed--;
        node->eow--;
    }

    int find(string &s) {
        Trie *node = this;
        int res = 0;
        for (char &c : s) {
            int i = c-'a';
            if (!node->children[i]) break;
            res++;
            node = node->children[i];
            if (node->eow) return res;
        }

        return node && node->eow ? res : -1;
    }
};


class Solution {
public:
    void convertLine(string s, vector<string> &res) {
        string val;
        stringstream ss(s);
        while (getline(ss, val, ' ')) res.push_back(val);
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (auto &s : dictionary) trie.insert(s);

        vector<string> words;
        convertLine(sentence, words);
        int x = trie.find(words[0]);
        string res = (x == -1 ? words[0] : words[0].substr(0, x));
        for (int i = 1; i < words.size(); i++) {
            res += " ";
            x = trie.find(words[i]);
            res += (x == -1 ? words[i] : words[i].substr(0, x));
        }
        return res;
    }
};
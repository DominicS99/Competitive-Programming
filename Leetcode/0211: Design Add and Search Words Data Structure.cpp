class WordDictionary {
public:
    vector<WordDictionary*> kids;
    bool isWord;

    WordDictionary() {
        kids.assign(26, nullptr);
        isWord = false;
    }
    
    void addWord(string word) {
        WordDictionary * curr = this;
        for (char &c : word) {
            if (!curr->kids[c-'a']) {
                curr->kids[c-'a'] = new WordDictionary();
            }
            curr = curr->kids[c-'a'];
        }
        curr->isWord = true;
    }

    bool searchHelp(string &word, int index, WordDictionary *root) {
        if (!root) return false;
        if (index == word.size()) return root->isWord;

        char c = word[index];
        if (c != '.') {
            return searchHelp(word, index+1, root->kids[c-'a']);
        }
        
        for (auto &v : root->kids) {
            if (searchHelp(word, index+1, v)) return true;
        }

        return false;
    }
    
    bool search(string word) {
        return searchHelp(word, 0, this);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

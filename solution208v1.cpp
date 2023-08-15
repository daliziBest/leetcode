//c++使用nullptr，不使用null

class Trie {
public:
    Trie() {
        pointerAlphabet.assign(26, nullptr);
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* child = this;
        for (auto c : word) {
            if ((*child).pointerAlphabet[c - 'a'] == nullptr) {
                (*child).pointerAlphabet[c - 'a'] = new Trie();
                child = (*child).pointerAlphabet[c - 'a'];
            } else {
                child = (*child).pointerAlphabet[c - 'a'];
            }
        }

        (*child).isEnd = true;
    }
    
    bool search(string word) {
        Trie* child = this;
        for (auto c : word) {
            if ((*child).pointerAlphabet[c - 'a'] == nullptr) {
                return false;
            } else {
                child = (*child).pointerAlphabet[c - 'a'];
            }
        }

        if ((*child).isEnd) {
            return true;
        } else {
            return false;
        }
        
    }
    
    bool startsWith(string prefix) {
        Trie* child = this;
        for (auto c : prefix) {
            if ((*child).pointerAlphabet[c - 'a'] == nullptr) {
                return false;
            } else {
                child = (*child).pointerAlphabet[c - 'a'];
            }
        }

        return true;
    }

private:
    vector<Trie*> pointerAlphabet;
    bool isEnd;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
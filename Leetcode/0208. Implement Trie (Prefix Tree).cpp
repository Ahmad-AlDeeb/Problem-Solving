class Trie {
    map<char, Trie*> root;
    bool isLeaf{};

public:
    Trie() {}
    
    void insert(string word) {
        Trie* cur = this;

        for(auto ch : word) {
            if(!cur->root[ch])
                cur->root[ch] = new Trie();
            cur = cur->root[ch];
        }

        cur->isLeaf = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for(auto ch : word) {
            if(cur->root.count(ch)) {
                cur = cur->root[ch];
            }
            else return false;
        }
        return cur->isLeaf;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for(auto ch : prefix) {
            if(cur->root.count(ch)) {
                cur = cur->root[ch];
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

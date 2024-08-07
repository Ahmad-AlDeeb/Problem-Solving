class MagicDictionary {
	map<char, MagicDictionary*> child;
	bool isLeaf{};

public:
    MagicDictionary() {}
    
    void insert(string str) {
		MagicDictionary* cur = this;

		for (int i{}; i<str.size(); ++i) {
			char ch = str[i];

			if (!cur->child[ch])
				cur->child[ch] = new MagicDictionary();

			cur = cur->child[ch];
		}
		cur->isLeaf = true;
	}
    
    void buildDict(vector<string> dictionary) {
        for(auto str : dictionary) {
            insert(str);
        }
    }
    
    bool search(string str, int i, int changes) {
        if(i == str.size()) {
            if(isLeaf && changes == 1) {
                return true;
            }
            else {
                return false;
            }
        }

        char ch = str[i];

        for(auto node : child) {            
            bool ans;
            if(node.first != ch) {
                if(!changes) ans = node.second->search(str, i+1, changes+1);
            }
            else {
                ans = node.second->search(str, i+1, changes);
            }
            
            if(ans) {
                return true;
            }
        }
        return false;
    }    

    bool search(string searchWord) {
        return search(searchWord, 0, 0);    
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

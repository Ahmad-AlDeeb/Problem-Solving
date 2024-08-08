class Trie {
	map<char, Trie*> child;
    int max_index{-1};

    public:
	Trie() {}

	void insert(const string& str, int index) {
		Trie* cur = this;

		for (int i{}; i <str.size(); ++i) {
			char ch = str[i];
			if (!cur->child[ch])
				cur->child[ch] = new Trie();
            cur = cur->child[ch];
            cur->max_index = index;
		}
	}
	int get_max_index(string str, int i = 0) {
		Trie* cur = this;

		for(int i{}; i<str.size(); i++) {
			char ch = str[i];
			if (!cur->child[ch])
				return -1;	// such path don't exist
			cur = cur->child[ch];
		}
		return cur->max_index;
	}
};


vector<string> generate_suf_pre(string str) {
    vector<string> result;
    for(int i{}; i<str.size(); i++) {
        result.push_back(str.substr(i) + "#" + str);
    }
    return result;
}


class WordFilter {
    Trie trie;
public:
    WordFilter(vector<string>& words) {
        for(int i{}; i<words.size(); i++) {
            vector<string> new_combinations = generate_suf_pre(words[i]);
            for(auto new_word : new_combinations) {
                trie.insert(new_word, i);
            }
        }
        
    }
    
    int f(string pref, string suff) {
        string target = suff + "#" +  pref;
        return trie.get_max_index(target);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */

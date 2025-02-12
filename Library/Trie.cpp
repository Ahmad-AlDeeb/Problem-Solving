class TrieNode {
	unordered_map<char, TrieNode*> children;
	bool isEndOfWord{};

public:
    TrieNode() {} 
    TrieNode(vector<string> dictionary) {
        for(auto str : dictionary) {
            insert(str);
        }
    }
    
    void insert(string word) {
		TrieNode* cur = this;

		for (int i{}; i<word.size(); ++i) {
			char curChar = word[i];

			if (cur->children.find(curChar) == cur->children.end()) {
                cur->children[curChar] = new TrieNode();
            }
	
			cur = cur->children[curChar];
		}
		cur->isEndOfWord = true;
	}
    
    
    bool search(string word, int index = 0) {
        if(index == word.size()) {
            return isEndOfWord;
        }

        char curChar = word[index];
        if (children.find(curChar) != children.end()) {
            return children[curChar]->search(word, index + 1);
        }
        return false;
    }    
};

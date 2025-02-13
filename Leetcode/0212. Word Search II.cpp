class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word = "";


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
		cur->word = word;
	}
};

class Solution {
    const vector<int> di = {-1, 1, 0, 0};
    const vector<int> dj = {0, 0, 1, -1};
    int m, n;
    set<string> foundWords;
    TrieNode* trie;
    
    bool isValid(vector<vector<char>>& board, int row, int col) {
        if(row < 0 || row >= m || col < 0 || col >= n || board[row][col] == '#') {
            return false;
        }
        return true;
    }

    void traverse(vector<vector<char>>& board, int row, int col, TrieNode* node) {
        char curChar = board[row][col];
        if(!node->children.count(curChar)) {
            return;
        }
        node = node->children[curChar];

        if(!node->word.empty()) {
            foundWords.insert(node->word);
        }

        board[row][col] = '#';
        for(int d{}; d < 4; ++d) {
            int newRow = row + di[d];
            int newCol = col + dj[d];
            
            if(isValid(board, newRow, newCol)) {
                traverse(board, newRow, newCol, node);
            }
        }
        board[row][col] = curChar;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        trie = new TrieNode(words);
        
        for(int row{}; row < m; ++row) {
            for(int col{}; col < n; ++col) {
                traverse(board, row, col, trie);
            }
        }
        return vector<string>(foundWords.begin(), foundWords.end());
    }
};

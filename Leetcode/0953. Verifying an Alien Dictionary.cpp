class Solution {
    unordered_map<char,int> rank;

    bool isSmaller(string word1, string word2) {
        int smallerSize = min(word1.size(), word2.size());
        
        for(int i{}; i < smallerSize; ++i) {
            if(rank[word1[i]] < rank[word2[i]]) {
                return true;
            }
            else if(rank[word1[i]] > rank[word2[i]]) {
                return false;
            }
        }
        
        if(word1.size() > word2.size()) {
            return false;
        }

        return true;
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i{}; i < order.size(); ++i) {
            rank[order[i]] = i;
        }

        for(int i{}; i < words.size() - 1; ++i) {
            if(!isSmaller(words[i], words[i+1])) {
                return false;
            }
        }
        return true;
    }
};

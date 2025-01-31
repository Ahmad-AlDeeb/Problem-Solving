bool customSort(const pair<int, string>& lhs, const pair<int, string>& rhs) {
    if(lhs.first != rhs.first) {
        return lhs.first > rhs.first;
    }
    else return lhs.second < rhs.second;
}

class Solution {
    vector<string> words;
    int k;
    unordered_map<string, int> count;

    void ini(vector<string>& _words, int _k) {
        words = _words;
        k = _k;
    }

    void buildCount() {
        for(auto word : words) {
            count[word]++;
        }
    }

    vector<string> sortWords() {
        vector<pair<int, string>> words;
        for(auto p : count) {
            words.emplace_back(p.second, p.first);
        }
        sort(words.begin(), words.end(), customSort);

        vector<string> sortedWords;
        for(auto p : words) {
            sortedWords.push_back(p.second);
            if(sortedWords.size() == k) {
                break;
            }
        }
        
        return sortedWords;
    }

public:
    vector<string> topKFrequent(vector<string>& _words, int _k) {
        ini(_words, _k);
        buildCount();
        return sortWords();
    }
};

class Solution {
    map<string, bool> uniqueDict;
    vector<string> dictionary;
    string sentence;

    void ini(vector<string>& _dictionary, string _sentence) {
        dictionary = _dictionary;
        sentence = _sentence;
    }
    
    void buildUniqueDict() {
        for(auto token : dictionary) {
        	uniqueDict[token] = true;
        }
    }

    vector<string> parseWords(string str) {
        vector<string> words;
        string currentWord{};
        
        for(int i{}; i < str.size(); ++i) {
            char currentChar = str[i];
            if(currentChar == ' ') {
                words.push_back(currentWord);
                currentWord.clear();
            }
            else currentWord += currentChar;
        }
        words.push_back(currentWord);
        
        return words;
    }

    string getRoot(string word) {
        string subWord{};
        string root {word};

        for(int i{}; i < word.size(); ++i) {
            subWord += word[i];
            if(uniqueDict[subWord]) {
                return subWord;
            }
        }
        return word;
    }
public:
    string replaceWords(vector<string>& _dictionary, string _sentence) {
        ini(_dictionary, _sentence);
        buildUniqueDict();
        vector<string> sentenceWords = parseWords(sentence);
        
        string answer{};
        int sentenceSize = sentenceWords.size();
        for(int i{}; i < sentenceSize; ++i) {
            answer += getRoot(sentenceWords[i]);
            
            if(i != sentenceSize - 1) {
                answer += ' ';
            }
        }

        return answer;
    }
};

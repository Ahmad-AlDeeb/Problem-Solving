class Solution {
    string s;
    vector<string> wordDict;
    vector<int> cache;

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this-> s = s;
        this-> wordDict = wordDict;
        int stringSize = s.size();

        cache = vector<int>(stringSize, -1);

        return isBreakable(stringSize - 1);
    }

    bool isBreakable(int index) {
        if(index < 0) {
            return true;
        }

        int &answer = cache[index];
        if(answer != -1) {
            return answer;
        }

        for(auto word : wordDict) {
            int wordSize = word.size();
            if(index - wordSize + 1 < 0) {
                continue;
            }

            string subString = s.substr(index - wordSize + 1, wordSize);
            if(subString == word && isBreakable(index - wordSize)) {
                return answer = 1;
            }
        }
        return answer = 0;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// Recursive DP Solution //////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// BFS Solution //////////////////////////////////////////
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        int strSize = s.size();
        
        vector<bool> visited(strSize);
        queue<int> nodes;
        nodes.push(0);

        while(!nodes.empty()) {
            int start = nodes.front();
            nodes.pop();

            if(start == strSize) {
                return true;
            }

            for(int end = start + 1; end <= strSize; ++end) {
                if(visited[end]) {
                    continue;
                }

                if(wordDictSet.find(s.substr(start, end - start)) != wordDictSet.end()) {
                    visited[end] = true;
                    nodes.push(end);
                }
            }
        }
        return false;
    }
};

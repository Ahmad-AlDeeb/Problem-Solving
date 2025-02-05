class Solution {
    set<string> answer;

    bool isValidNum(string num) {
        if(num[0] == '0' && num.size() > 1) {
            return false;
        }
        return stoll(num) >= 0 && stoll(num) <= 255;
    }

    pair<string, bool> buildAddress(string s, vector<int> chosenIndex) {
        string address{};
        string curNum{};
        const pair<string, bool> FALSE_ADDRESS = make_pair("", false);

        for(int i{}; i < s.size(); ++i) {
            int curChar = s[i];

            if(!isdigit(curChar)) {
                return FALSE_ADDRESS;
            }

            curNum += curChar;
            if(find(chosenIndex.begin(), chosenIndex.end(), i) != chosenIndex.end()) {
                if(!isValidNum(curNum)) {
                    return FALSE_ADDRESS;
                }
                
                address += curNum;
                address += '.';
                curNum.clear();
            }
        }

        if(!isValidNum(curNum)) {
            return FALSE_ADDRESS;
        }        
        address += curNum;

        return make_pair(address, true);
    }

    void buildAnswer(string s, vector<int> chosenIndex, int index) {
        if(index >= s.size() || chosenIndex.size() > 3) {
            return;
        }

        if(chosenIndex.size() == 3) {
            auto buildResult = buildAddress(s, chosenIndex);
            
            if(buildResult.second) {
                answer.insert(buildResult.first);
            }
        }

        buildAnswer(s, chosenIndex, index + 1);
        
        chosenIndex.push_back(index);
        buildAnswer(s, chosenIndex, index + 1);
        chosenIndex.pop_back();
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> chosenIndex;
        buildAnswer(s, chosenIndex, 0);
        
        return vector<string>(answer.begin(), answer.end());
    }
};

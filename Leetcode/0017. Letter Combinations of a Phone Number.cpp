class Solution {
    unordered_map<char, vector<char>> digitToChar;
    vector<string> answer;

    void ini() {
        digitToChar['2'] = vector<char>{'a', 'b', 'c'};
        digitToChar['3'] = vector<char>{'d', 'e', 'f'};
        digitToChar['4'] = vector<char>{'g', 'h', 'i'};
        digitToChar['5'] = vector<char>{'j', 'k', 'l'};
        digitToChar['6'] = vector<char>{'m', 'n', 'o'};
        digitToChar['7'] = vector<char>{'p', 'q', 'r', 's'};
        digitToChar['8'] = vector<char>{'t', 'u', 'v'};
        digitToChar['9'] = vector<char>{'w', 'x', 'y', 'z'};
    }

    void buildAnswer(string digits, int index, string combination) {
        if(index >= digits.size()) {
            answer.push_back(combination);
            return;
        }
        
        for(auto letter : digitToChar[digits[index]]) {
            buildAnswer(digits, index + 1, combination + letter);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return vector<string>{};
        }
        
        ini();
        buildAnswer(digits, 0, "");
        return answer;
    }
};

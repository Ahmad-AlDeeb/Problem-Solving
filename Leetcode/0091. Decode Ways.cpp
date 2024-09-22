const int MAX = 100 + 1;

class Solution {
    int memory[MAX];
    string digits;
    int n;

    bool checkTwoDigits(int i) {
        if(i + 1 >= n)
            return false;

        int num = stoi(digits.substr(i, 2));
        return num >= 1 && num <= 26;
    }

    int getCount(int i) {
        if(i == n) 
            return 1;
        if(digits[i] == '0') 
            return 0;

        int &answer = memory[i];
        if(answer != -1)
            return answer;

        int oneOption = getCount(i + 1);
        int twoOption = checkTwoDigits(i) ? getCount(i + 2) : 0;
        return answer = oneOption + twoOption;
    }

public:
    int numDecodings(string s) {
        memset(memory, -1, sizeof(memory));
        digits = s;
        n = s.size();

        return getCount(0);
    }
};

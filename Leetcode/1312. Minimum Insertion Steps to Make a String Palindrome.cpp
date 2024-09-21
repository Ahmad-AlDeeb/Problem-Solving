int const MAX = 500 + 1;

class Solution {
int memory[MAX][MAX];
string word;
int n;

    int getMin(int start, int end) {
        if(start >= end) {
            return 0;
        }

        int &answer = memory[start][end];
        if(answer != -1) {
            return answer;
        }

        if(word[start] == word[end]) {
            return answer = getMin(start + 1, end - 1);
        } else {
            int insertRightOption = 1 + getMin(start + 1, end);
            int insertLeftOption = 1 + getMin(start, end - 1);

            return answer = min(insertRightOption, insertLeftOption);
        }
    }

public:
    int minInsertions(string s) {
        memset(memory, -1, sizeof(memory));
        word = s;
        n = s.size();

        return getMin(0, n - 1);
    }
};

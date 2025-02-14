class Solution {
    vector<string> answers;

    void generateParenthesis(int n, int openCount, int closeCount, string& answer) {
        if(closeCount > openCount) {
            return;
        }
        if(answer.size() == n) {
            if(closeCount == openCount) {
                answers.push_back(answer);
            }
            return;
        }

        answer += '(';
        generateParenthesis(n, openCount + 1, closeCount    , answer);
        answer.pop_back();

        answer += ')';
        generateParenthesis(n, openCount    , closeCount + 1, answer);
        answer.pop_back();
    }

public:
    vector<string> generateParenthesis(int n) {
        string answer;
        generateParenthesis(n * 2, 0, 0, answer);
        return answers;
    }
};

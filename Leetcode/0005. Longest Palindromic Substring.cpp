const int N = 1000 + 1;

class Solution {
int memory[N][N];
string word;
int n;

int isPalindrome(int start, int end) {
    if(start >= end) {
        return 1;
    }

    int &answer = memory[start][end];
    if(answer != -1) {
        return answer;
    }

    if(word[start] == word[end]) {
        return answer = isPalindrome(start + 1, end - 1);
    } else {
        return answer = 0;
    }
}

pair<int,int> getLongest() {
    int mx{};
    pair<int,int> answer;

    for(int start{}; start < n; ++start) {
        for(int end{start}; end < n; ++end) {
            memory[start][end] = isPalindrome(start, end);

            if(!memory[start][end]) {
                continue;
            }

            int size = end - start + 1;
            if(size > mx) {
                mx = size;
                answer = {start, end};
            }
        }
    }

    return answer;
}

public:
    string longestPalindrome(string s) {
        word = s;
        n = word.size();
        memset(memory, -1, sizeof(memory));
        
        auto answer = getLongest();
        
        int size {answer.second - answer.first + 1};
        return s.substr(answer.first, size);
    }
};

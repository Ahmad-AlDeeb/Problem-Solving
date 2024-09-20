int const N = 58 + 1;
class Solution {
int memory[N];

    int getAns(int n) {
        if(n <= 3) {
            return n;
        }
        
        int &answer = memory[n];
        if(answer != -1) {
            return answer;
        }

        for(int i{1}; i <= n/2; ++i) {
            answer = max(answer, i * getAns(n - i));
        }
        return answer;
    }

public:
    int integerBreak(int n) {
        if(n <= 3) {
            return n-1;
        }

        memset(memory, -1, sizeof(memory));
        return getAns(n);
    }
};

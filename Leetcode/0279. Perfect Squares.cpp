const int N = 10000 + 1;

class Solution {
    int memory[N];
    vector<int> perfectSquares;
    
    vector<int> generatePerfectSquares() {
        vector<int> perfectSquares;
        for(int i{1}; i <= 100; i++) {
            perfectSquares.push_back(i*i);
        }
        return perfectSquares;
    }

    int getAnswer(int n) {
        if(n == 0) {
            return 0;
        }

        int &answer = memory[n];
        if(answer != -1) {
            return answer;
        }

        answer = N;
        for(auto ps : perfectSquares) {
            if(ps <= n) {
                answer = min(answer, 1 + getAnswer(n - ps));
            }
        }
        return answer;
    }

public:
    int numSquares(int n) {
        perfectSquares = generatePerfectSquares();
        memset(memory, -1, sizeof(memory));
        return getAnswer(n);
    }
};

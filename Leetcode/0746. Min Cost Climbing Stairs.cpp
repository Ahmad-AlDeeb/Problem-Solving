const int N = 1000 + 1;

class Solution {
    int memroy[N];
    vector<int> stairs;
    int n;

    int getAnswer(int i) {
        if(i >= n) {
            return 0;
        }

        int &answer = memroy[i];
        if(answer != -1) {
            return answer;
        }

        int oneStepOption = stairs[i] + getAnswer(i + 1);
        int twoStepOption = stairs[i] + getAnswer(i + 2);

        return answer = min(oneStepOption, twoStepOption);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        stairs = cost;
        n = stairs.size();
        memset(memroy, -1, sizeof(memroy));

        return min(getAnswer(0), getAnswer(1));
    }
};

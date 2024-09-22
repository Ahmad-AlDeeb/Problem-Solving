int const MAX = 100 + 2 + 1;

class Solution {
    int memory[MAX][MAX];
    vector<int> cut;
    int cutsSize;
    
    int getAnswer(int start, int end) {
        if(start + 1 == end)
            return 0;

        int &answer = memory[start][end];
        if(answer != -1)
            return answer;
        answer = INT_MAX;
        
        int cost = cut[end] - cut[start];
        for(int split{start + 1}; split < end; ++split) {
            int leftAnswer = getAnswer(start, split);
            int rightAnswer = getAnswer(split, end);
            answer = min(answer, cost + leftAnswer + rightAnswer);
        }
        return answer;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        memset(memory, -1, sizeof(memory));
        cut = cuts;
        
        cut.push_back(0);
        cut.push_back(n);
        sort(cut.begin(), cut.end());
        cutsSize = cut.size();

        return getAnswer(0, cutsSize - 1);
    }
};

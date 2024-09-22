const int MAX = 300 + 2 + 1;

class Solution {
    int memory[MAX][MAX];
    vector<int> balloons;
    int n;

    int getAnswer(int start, int end) {
        if(start > end)
            return 0;
        
        int &answer = memory[start][end];
        if(answer != -1) 
            return answer;
        
        for(int split{start}; split <= end; ++split) {
            int coins = balloons[start - 1] * balloons[split] * balloons[end + 1];
            answer = max(answer, coins + getAnswer(start, split - 1) + getAnswer(split + 1, end));
        }
        return answer;
    }


public:
    int maxCoins(vector<int>& nums) {
        memset(memory, -1, sizeof(memory));
        balloons = nums;

        balloons.insert(balloons.begin(), 1);
        balloons.push_back(1);
        n = balloons.size();

        return getAnswer(1, n - 2);
    }
};

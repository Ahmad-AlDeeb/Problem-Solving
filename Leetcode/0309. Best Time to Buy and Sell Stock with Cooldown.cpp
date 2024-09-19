enum {BUY = true, SELL = false};

class Solution {
    vector<int> stocks;
    int memory[5001][2];
    int n;

    int getMaxProfit(int i, bool state) {
        if(i >= n) {
            return 0;
        }

        int &answer = memory[i][state];
        if(answer != -1) {
            return answer;
        }

        int actionOption{};
        int waitOption = getMaxProfit(i + 1, state);
        
        if(state == SELL) {
            actionOption = -stocks[i] + getMaxProfit(i + 1, BUY);
        }
        else {
            actionOption = +stocks[i] + getMaxProfit(i + 2, SELL);
        }

        return answer = max(actionOption, waitOption);
    }

public:
    int maxProfit(vector<int>& prices) {
        stocks = prices;
        n = stocks.size();
        memset(memory, -1, sizeof(memory));

        return getMaxProfit(0, SELL);
    }
};

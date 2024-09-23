int const MAX_COINS = 300 + 1;
int const MAX_AMOUNT = 5000 + 1;

class Solution {
    int memory[MAX_COINS][MAX_AMOUNT];
    vector<int> coins2;

    int getCount(int i, int remain) {
        if(remain == 0)
            return 1;
        if(remain < 0 || i == coins2.size())
            return 0;

        int &count = memory[i][remain];
        if(count != -1)
            return count;

        int takeOption = getCount(i, remain - coins2[i]);
        int leaveOption = getCount(i + 1, remain);
            
        return count = takeOption + leaveOption;
    }

public:
    int change(int amount, vector<int> coins) {
        memset(memory, -1, sizeof(memory));
        coins2 = coins;
    
        return getCount(0, amount);
    }
};

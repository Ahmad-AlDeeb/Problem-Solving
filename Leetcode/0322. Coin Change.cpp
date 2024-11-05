const int COINS_SIZE = 12 + 1;
const int REMAINING = 1e4;
const int MAX_ANSWER = INT_MAX / 2;

class Solution {
    vector<int> coins;
    int memo[COINS_SIZE][REMAINING];
    int n;

    int change(int i, int remaining) {
        if(!remaining) {
            return 0;
        }

        if(i >= n) {
            return MAX_ANSWER;
        }

        int &count = memo[i][remaining];
        if(count != -1) {
            return count;
        }

        int takeOption {MAX_ANSWER};
        if(coins[i] <= remaining) {
            takeOption = 1 + change(i, remaining - coins[i]);
        }
        int leaveOption = change(i + 1, remaining);

        return count = min(takeOption, leaveOption);
    }
public:
    int coinChange(vector<int>& coins_, int amount) {
        coins = coins_;
        memset(memo, -1, sizeof(memo));
        n = coins.size();        
        
        sort(coins.begin(), coins.end(), greater<>());
        
        int answer = change(0, amount);
        return (answer == MAX_ANSWER)? -1 : answer;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur{prices.front()};
        int ans{};

        for(int i{1}; i<prices.size(); i++) {
            if(prices[i] < cur) cur = prices[i];
            else                ans = max(ans, prices[i]-cur);
        }
    
        return ans;
    }
};

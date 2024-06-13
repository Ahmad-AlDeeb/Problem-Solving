class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi{};
        for(auto candy : candies)
            maxi = max(maxi, candy);

        vector<bool> ans(candies.size());
        for(int i{}; i<ans.size(); i++) {
            if(candies[i] + extraCandies >= maxi)
                ans[i] = true;
        }

        return ans;
    }
};

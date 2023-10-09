class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {

        vector<int> ans(temp.size());
        stack<pair<int,int>> s;

        for(int i{}; i<temp.size(); i++) {
            

            while(!s.empty() and temp[i] > s.top().second) {
                ans[s.top().first] = i-s.top().first;
                s.pop();
            }

            s.emplace(i,temp[i]);
        }

        return ans;
    }
};

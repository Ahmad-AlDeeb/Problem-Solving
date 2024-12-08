class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, vector<long long>> locations;
        for(int i{}; i < arr.size(); ++i) 
            locations[arr[i]].push_back(i);
        
        vector<long long> ans(n);

        for(auto &p : locations) {
            vector<long long> index = p.second;
            vector<long long> pre = index;

            for(int i{1}; i < pre.size(); ++i) {
                pre[i] += pre[i - 1];
            }

            int n = index.size();
            for(int i{}; i < n; ++i) {
                long current = index[i];
                
                if(i == 0) {
                    ans[current] = (pre[n - 1] - pre[i]) - (current * (n-1));
                }
                else if(i == n - 1) {
                    ans[current] = (current * (n-1)) - (pre[i - 1]);
                }
                else {
                    long afterSum = (pre[n - 1] - pre[i]) - current * (n-1-i);
                    long beforeSum = (current * i) - pre[i-1];
                    ans[current] = afterSum + beforeSum;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<pair<int,int>> job(n);
        for(int i{}; i<profit.size(); i++) {
            job[i] = make_pair(profit[i], difficulty[i]);
        }
        
        sort(job.rbegin(), job.rend());
        sort(worker.rbegin(), worker.rend());
        
        int m = worker.size();
        int maxProfit{};
        for(int i{}, j{}; i<n && j<m;) {
            if(worker[j] >= job[i].second) {
                maxProfit += job[i].first;
                j++;
            }
            else {
                i++;
            }
        }
        return maxProfit;
    }
};

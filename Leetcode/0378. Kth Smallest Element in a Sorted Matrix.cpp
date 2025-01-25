class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> pq;

        for(int i{}; i < n; ++i) {
            for(int j{}; j < n; ++j) {
                int current = matrix[i][j];

                if(pq.size() < k) {
                    pq.push(current);
                }
                else if(current < pq.top()) {
                    pq.pop();
                    pq.push(current);
                }
            }
        }
        return pq.top();
    }
};

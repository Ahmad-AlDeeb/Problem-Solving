const int MAX_TIME = 1e6;

class Solution {
    vector<int> bellman(vector<vector<int>> edges, int n, int src) {
        vector<int> shortestPath(n, MAX_TIME);
        shortestPath[src] = 0;

        int iterations {n - 1};
        while(iterations--)
            for (auto edge : edges) {
                int from = edge[0];
                int to = edge[1];
                int time = edge[2];

                if(shortestPath[to] > shortestPath[from] + time)
                    shortestPath[to] = shortestPath[from] + time;
            }
        return shortestPath;
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto &time : times) {
            time[0]--;
            time[1]--;
        }
        k--;

        vector<int> shortestPath = bellman(times, n, k);

        int answer = *max_element(shortestPath.begin(), shortestPath.end());
        return (answer == MAX_TIME)? -1 : answer;
    }
};

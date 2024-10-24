const int MOD = 1e9 + 7;
struct Edge {
    int to;
    long long weight;

    Edge(int to, long long weight) : to(to), weight(weight) {}

    bool operator< (const Edge &edge) const {
        return weight > edge.weight;
    }
};

class Solution {
    int dijkstra(vector<vector<Edge>>& adjList, int n) {
        vector<long long> dist(n, LLONG_MAX);
        vector<bool> vis(n);
        dist[0] = 0;

        vector<int> pathsCount(n, 0);
        pathsCount[0] = 1;

        priority_queue<Edge> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            Edge minEdge = pq.top();
            int minTo = minEdge.to;
            pq.pop();

            if(vis[minTo])
                continue;

            for(auto edge : adjList[minTo]) {
                int to = edge.to;
                int weight = edge.weight;

                if(dist[to] == dist[minTo] + weight) {
                    pathsCount[to] += pathsCount[minTo];
                    pathsCount[to] %= MOD;
                }
                else if(dist[to] > dist[minTo] + weight) {
                    pathsCount[to] = pathsCount[minTo];

                    dist[to] = dist[minTo] + weight;
                    pq.push({to, dist[to]});
                }
            }
            vis[minTo] = true;
        }
        return pathsCount[n - 1];
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<Edge>> adjList(n);
        for(auto road : roads) {
            adjList[road[0]].push_back({road[1], road[2]});
            adjList[road[1]].push_back({road[0], road[2]});
        }

        return dijkstra(adjList, n);
    }
};

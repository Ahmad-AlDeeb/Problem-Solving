const int MOD = 1e9 + 7;
const int N = 2 * 1e4 + 1;
struct Edge  {
    int to, weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
    bool operator< (const Edge &e) const {
        return weight > e.weight;
    }
};

class Solution {
    vector<int> SP;
    long long cache[N];

    vector<int> dijkstra(vector<vector<Edge>> &adjList, int n) {
        vector<int> dist(n + 1, INT_MAX);
        dist[n] = 0;
        vector<bool> vis(n + 1);

        priority_queue<Edge> edges;
        edges.push( {n, 0} );

        while(!edges.empty()) {
            Edge minEdge = edges.top();
            int minTo = minEdge.to;
            edges.pop();

            if(vis[minTo]) {
                continue;
            }

            for(Edge edge : adjList[minTo]) {
                int to = edge.to;
                int weight = edge.weight;

                if(dist[to] > dist[minTo] + weight) {
                    dist[to] = dist[minTo] + weight;
                    edges.push( {to, dist[to]} );
                }
            }
            vis[minTo] = true;
        }
        return dist;
    }

    long long pathsCount(int src, int target, vector<vector<Edge>> &adjList) {
        if(src == target) {
            return 1;
        }

        long long &count = cache[src];
        if(count != -1) {
            return count;
        }
        count = 0;

        for(auto edge : adjList[src]) {
            if(SP[edge.to] < SP[src]) {
                count += pathsCount(edge.to, target, adjList);
                count %= MOD;
            }
        }
        return count;
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<Edge>> adjList(n + 1);
        for(auto edge : edges) {
            adjList[edge[0]].emplace_back(edge[1], edge[2]);
            adjList[edge[1]].emplace_back(edge[0], edge[2]);
        }

        SP = dijkstra(adjList, n);

        memset(cache, -1, sizeof(cache));
        return pathsCount(1, n, adjList);
    }
};

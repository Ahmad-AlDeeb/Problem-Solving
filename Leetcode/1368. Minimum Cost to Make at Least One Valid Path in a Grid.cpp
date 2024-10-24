const vector<int> di = {0, 0, 1, -1};
const vector<int> dj = {1, -1, 0, 0};
struct Edge {
    int to, weight;
    
    Edge(int to, int weight) : to(to), weight(weight) {

    }

    bool operator< (const Edge &e) const {
        return weight > e.weight;
    }
};

class Solution {
    int m, n;
    vector<vector<int>> grid;

    bool isValid(int i, int j) {
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }
    int getIndex(int i, int j) {
        return n * i + j;
    }

    int dijkstra(vector<vector<Edge>>& adjList, int size) {
        vector<int> dist(size, INT_MAX);
        vector<bool> vis(size);
        dist[0] = 0;

        priority_queue<Edge> edges;
        edges.push({0, 0});

        while(!edges.empty()) {
            Edge minEdge = edges.top();
            int minTo = minEdge.to;
            edges.pop();

            if(vis[minTo]) {
                continue;
            }
            
            for(auto edge : adjList[minTo]) {
                int to = edge.to;
                int weight = edge.weight;

                if(dist[to] > dist[minTo] + weight) {
                    dist[to] = dist[minTo] + weight;
                    edges.push( {to, dist[to]} );
                }
            }
            vis[minTo] = true;
        }
        return dist[size - 1];
    }
public:
    int minCost(vector<vector<int>>& grid_) {
        grid = grid_;
        m = grid.size();
        n = grid[0].size();
        int size = m * n;

        vector<vector<Edge>> adjList(size);
        for(int i{}; i < m; ++i) {
            for(int j{}; j < n; ++j) {
                int index = getIndex(i, j);
                int cellDir = grid[i][j] - 1; // minus 1 to be alined with  0-based indexing

                for(int d{}; d < 4; ++d) {
                    int i2 = i + di[d];
                    int j2 = j + dj[d];
                    if(!isValid(i2, j2)) {
                        continue;
                    }
                    
                    int weight = (cellDir != d);
                    int toIndex = getIndex(i2, j2);
                    adjList[index].push_back({toIndex, weight});
                }
            }
        }

        return dijkstra(adjList, size);
    }
};

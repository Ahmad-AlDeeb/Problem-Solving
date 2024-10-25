struct Edge {
    int to, weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
    bool operator< (const Edge& e) const {
        return weight > e.weight;
    }
};

class Solution {
    int n;
    vector<vector<int>> points;

    int getDist(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int prim(int n) {
        vector<int> minCost(n, 4 * 1e6 + 1);
        minCost[0] = 0;
        int mstCost{};
        vector<bool> vis(n);

        priority_queue<Edge> edges;
        edges.push( {0, 0} );

        while(!edges.empty()) {
            Edge minEdge = edges.top();
            edges.pop();
            int minTo = minEdge.to;

            if(vis[minTo]) {
                continue;
            }
            mstCost += minEdge.weight;

            for(int p{}; p < n; ++p) {
                if(p == minTo) {
                    continue;
                }
                
                int to = p;
                int weight = getDist(points[minTo][0], points[minTo][1], points[to][0], points[to][1]);

                if(minCost[to] > weight) {
                    minCost[to] = weight;
                    edges.push( {to, minCost[to]} );
                }
            }

            vis[minTo] = true;
        }
        return mstCost;
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points_) {
        points = points_;
        int n = points.size();
        return prim(n);
    }
};

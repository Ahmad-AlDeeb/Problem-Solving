/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
// Prim | Greedy | O(E log(V))
const int INF = (int) 1e6;
struct Edge {
	int to, w;

	Edge(int to, int w) : to(to), w(w) {
	}

	bool operator <(const Edge &e) const {
		return w > e.w;
	}
};

int prim(const vector<vector<Edge>> &adjList, int n, int src) {
	vector<int> minCost(n, INF);
	vector<bool> vis(n);
	dist[src] = 0;
	int mstCost {};

	priority_queue<Edge> q;	// small to large
	q.push(Edge(src, 0));

	while (!q.empty()) {
		// Get node with the minimum distance
		Edge minEdge = q.top();
		int minIndex = minEdge.to;
		q.pop();
		
		// The same node might come several times
		if (vis[minIndex]) {
			continue;
		}
		mstCost += minEdge.weight;
		
		// Relax with the outgoing edges of the min node
		for (const auto &edge : adjList[minIndex]) {
			int to = edge.to;
			int weight = edge.w;
			
			if (minCost[to] > weight) {
				minCost[to] = weight;
				// Add new edges
				q.push( {to, dist[to]} );
			}
		}
		vis[minIndex] = true;
	}
	return mstCost;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
// Kruskel | Greedy | O(E log(E))
class Dsu {
	vector<int> ccSize, parent;
	int treesCount;

	void link(int smallParent, int bigParent) {
		if (ccSize[smallParent] > ccSize[bigParent])
			swap(smallParent, bigParent);

		parent[smallParent] = bigParent;
	        ccSize[bigParent] += ccSize[smallParent];
	}
    public:
        Dsu(int n) {
            ccSize = vector<int>(n), parent = vector<int>(n);
            treesCount = n;	

            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                ccSize[i] = 1;
            }
        }

        int findParent(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findParent(parent[node]);
        }

        bool unionTrees(int node1, int node2) {
            int parent1 = findParent(node1);
            int parent2 = findParent(node2);
            
            if (parent1 != parent2) {	// Different components
                link(parent1, parent2);
                treesCount--;	// 2 merged into 1
            }
            return parent1 != parent2;
    	}
};

struct Edge {
	int from, to, weight;

	Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {
	}

	bool operator< (const Edge& e) const {
		return weight < e.weight;
	}
};

int kruskal(vector<Edge>& edges, int n) { 
	sort(edges.begin(), edges.end());
	Dsu dsu(n);
	int mstCost = 0;
	
	for(Edge& edge : edges) 
		if (dsu.unionTrees(edge.from, edge.to)) 
			mstCost += edge.weight;
	
	return mstCost;
}

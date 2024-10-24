/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
// Floyd-Warshal: APSP | DP | detect negative cycles | adjacency matrix | O(n3)
void floyd(vector<vector<int>>& shortestPath) {
  int n = shortestPath.size();
  
  for(int k{}; k < n; ++k) {
    for(int i{}; i < n; ++i) {
      for(int j{}; j < n; ++j) {
        int relax = shortestPath[i][k] + shortestPath[k][j];
        shortestPath[i][j] = min(shortestPath[i][j], relax);
      }
    }
  }
}

int main() {
  int n; // number of nodes
  cin >> n;
  
  vector<vector<int>> adjMatrix(n, vector<int>(n, 1e9));
  for(int i{}; i < n; ++i) {
    adjMatrix[i][i] = 0;
  }
  // Read graph as adjacent matrix
  
  floyd(adjMatrix);
  // Now adjMatrix have shortest path between all pairs
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
// Bellman-Ford: SSSP | DP | detect negative cycles | edge list | O(EV) O(n)
const int INF = (int) 1e6;
struct Edge {
	int from, to, w;

	Edge(int from, int to, int w) :
			from(from), to(to), w(w) {
	}
};

vector<int> bellman(vector<Edge> &edgeList, int n, int src) {
	vector<int> dist(n, INF);
	dist[src] = 0;

	int iterations {n - 1};
	while (iterations--)
		for (Edge edge : edgeList) {
			if (dist[edge.to] > dist[edge.from] + edge.w)
				dist[edge.to] = dist[edge.from] + edge.w;
		}
	return dist;
}

int main() {
  vector<Edge> edgeList; // Read graph as edge list
  int n; // Read number of nodes
  int src; // Read source node
  
  vector<int> shortestPath = bellman(edgeList, n, src);
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
// Dijkstra: SSSP | Greedy | non-negative weights only | O(E logV)
const int INF = (int) 1e6;
struct Edge {
	int to, w;

	Edge(int to, int w) : to(to), w(w) {
	}

	bool operator <(const Edge &e) const {
		return w > e.w;
	}
};
vector<int> Dijkstra(const vector<vector<Edge>> &adjList, int n, int src) {
	vector<int> dist(n, INF);
	vector<bool> vis(n);
	dist[src] = 0;

	priority_queue<Edge> q;	// small to large
	q.push(Edge(src, 0));

	while (!q.empty()) {
		// Get node with the minimum distance
		Edge minEdge = q.top();
		int minIndex = minEdge.to;
		q.pop();

		// The same node might come several times
		if (vis[minIndex])
			continue;

		// Relax with the outgoing edges of the min node
		for (const auto &edge : adjList[minIndex]) {
			int to = edge.to, weight = edge.w;

			if (dist[to] > dist[minIndex] + weight) {
				dist[to] = dist[minIndex] + weight;
				// Add new edges
				q.push( {to, dist[to] });
			}
		}
		vis[minIndex] = true;
	}
	return dist;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
// Floyd-Warshal: all pairs | DP | detect negative cycles | adjacency matrix | O(n3)
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
// Bellman-Ford: single source | DP | detect negative cycles | edge list | O(n2) O(n)
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
// Dijkstra: single source | Greedy | non-negative weights only

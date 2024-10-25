/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
// Prim | Greedy | O(E logV)
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
	vector<int> dist(n, INF);
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

			if (dist[to] > weight) {
				dist[to] = weight;
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
// Kruskel ???

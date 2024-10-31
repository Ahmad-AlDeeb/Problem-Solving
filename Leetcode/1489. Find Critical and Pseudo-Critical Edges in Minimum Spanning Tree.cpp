class Dsu {
	vector<int> rank, parent;
	int treesCount;

	void link(int smallParent, int bigParent) {
		if (rank[smallParent] > rank[bigParent])
			swap(smallParent, bigParent);

		parent[smallParent] = bigParent;
		if (rank[smallParent] == rank[bigParent])
			rank[bigParent]++;
	}
    public:
        Dsu(int n) {
            rank = vector<int>(n), parent = vector<int>(n);
            treesCount = n;	

            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                rank[i] = 1;
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

struct edge {
	int from, to, w, idx;

	edge(int from, int to, int w, int idx) :
			from(from), to(to), w(w), idx(idx) {
	}

	bool operator <(const edge &e) const {
		return w < e.w;
	}
};

int kruskal(const vector<edge> &edges, int n, const vector<edge> &edgeToAdd, const set<int> &edgeToSkip) {
	Dsu dsu(n);
	int mstCost = 0;

	for (auto &e : edgeToAdd)	// force adding to built network
		if (dsu.unionTrees(e.from, e.to))
			mstCost += e.w;

	for (auto &e : edges)	// ignore the index if requested
		if (!edgeToSkip.count(e.idx) && dsu.unionTrees(e.from, e.to))
			mstCost += e.w;

	return mstCost;
}

vector<edge> convertEdges(vector<vector<int>>& edges_) {
    vector<edge> edges;
    
    for(int i{}; i < edges_.size(); ++i) {
        edge edge(edges_[i][0], edges_[i][1], edges_[i][2], i);
        edges.push_back(edge);
    }

    return edges;
}

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges_) {
        vector<edge> edges = convertEdges(edges_);
        sort(edges.begin(), edges.end());

        int mstCost = kruskal(edges, n, { }, { });

        vector<int> critical, pseudo;
        
        for(auto edge : edges) {
            int costWithForcedEdge = kruskal(edges, n, { edge }, { });
            if(costWithForcedEdge > mstCost) {
                continue;
            }

            int costWithSkippedEdge = kruskal(edges, n, { }, { edge.idx });
            if(costWithSkippedEdge == mstCost) {
                pseudo.push_back(edge.idx);
            }
            else {
                critical.push_back(edge.idx);
            }
        }

        return {critical, pseudo};
    }
};

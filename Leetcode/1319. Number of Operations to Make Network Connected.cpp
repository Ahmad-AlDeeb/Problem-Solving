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

        int getTreesCount() {
            return treesCount;
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Dsu dsu(n);
        int edgesCount = connections.size();

        if(edgesCount < n - 1) {
            return -1;
        }

        for(int i{}; i < edgesCount; ++i) {
            int a = connections[i][0];
            int b = connections[i][1];
            dsu.unionTrees(a, b);
        }

        return dsu.getTreesCount() - 1;
    }
};

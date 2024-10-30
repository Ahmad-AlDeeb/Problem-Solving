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

        int getTreesCount() {
            return treesCount;
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

class Solution {
    int n;
    
    bool isSimilar(string str1, string str2) {
        int size = str1.size();
        int changesCount {};

        for(int i{}; i < size; ++i) {
            if(str1[i] != str2[i])
                changesCount++;
        }

        if(changesCount <= 2) {
            return true;
        }
        return false;
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        n = strs.size();
        Dsu dsu(n);
        
        for(int i{}; i < n; ++i) {
            for(int j{i + 1}; j < n; ++j) {
                if(isSimilar(strs[i], strs[j]))
                    dsu.unionTrees(i, j);
            }
        }

        return dsu.getTreesCount();
    }
};

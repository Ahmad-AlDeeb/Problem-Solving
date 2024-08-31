class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        if(org.empty()) {
            return true;
        }
        if(seqs.empty()) {
            return false;
        }
        
        unordered_map<int, unordered_set<int>> adjacent;
        for(auto seq : seqs) {
            for(int i{}; i < (int) seq.size() - 1; ++i) {
                adjacent[seq[i]].insert(seq[i+1]);
            }
            if(seq.size() == 1) {
                unordered_set<int> emptySet;
                adjacent[seq.front()] = emptySet;
            }
        }
        if(adjacent.empty()) {
            return false;
        }

        int n = org.size();
        vector<int> inDegree(n + 1);
        for(auto relation : adjacent) {
            for(auto child : relation.second) {
                if(child > n) {
                    return false;
                }
                inDegree[child]++;
            }
        }

        queue<int> nodes;
        for(int node{1}; node <= n; ++node) {
            if(!inDegree[node]) {
                nodes.push(node);
            }
        }

        vector<int> order;
        while(!nodes.empty()) {
            if(nodes.size() > 1) {
                return false;
            }
            
            int current = nodes.front();
            nodes.pop();
            order.push_back(current);

            for(auto child : adjacent[current]) {
                if(!--inDegree[child]) {
                    nodes.push(child);
                }
            }
        }

        if(order.size() != n) {
            return false;
        }

        for(int i{}; i < n; ++i) {
            if(order[i] != org[i]) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
    unordered_map<int,vector<int>> adj;
    unordered_set<int> vis;

    void dfs(int node, vector<int> &answer, int i = 0) {
        if(vis.count(node)) {
            return;
        }
        vis.insert(node);

        answer[i] = node;

        for(auto child : adj[node]) {
            dfs(child, answer, i+1);
        }
    }

public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(auto p : adjacentPairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        int start;
        for(auto child : adj) {
            if(child.second.size() == 1) {
                start = child.first;
                break;
            }
        }
        cout << "LOL";
        vector<int> answer(adjacentPairs.size()+1);
        dfs(start, answer);
        return answer;
    }
};

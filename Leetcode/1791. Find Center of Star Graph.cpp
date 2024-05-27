class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        set<int> visited;

        for(int i{}; i<edges.size(); i++) {
                int node1 = edges[i][0];
                int node2 = edges[i][1];

                if(visited.find(node1) != visited.end())
                    return node1;
                if(visited.find(node2) != visited.end())
                    return node2;

                visited.insert(node1);
                visited.insert(node2);
        }
                
        return 0;
    }
};

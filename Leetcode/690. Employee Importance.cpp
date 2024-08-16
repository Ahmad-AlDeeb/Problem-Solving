/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> id_to_importance;

public:
    int dfs(int node) {
        int importance = id_to_importance[node];
        for(auto child : adj[node]) {
            importance += dfs(child);
        }
        return importance;
    }

    int getImportance(vector<Employee*> employees, int id) {
        for(auto emp : employees) {
            int cur_id = emp->id;
            id_to_importance[cur_id] = emp->importance;
            for(auto sub : emp->subordinates) {
                adj[cur_id].push_back(sub);
            }
        }
        return dfs(id);  
    }
};

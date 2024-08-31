class Solution {    
    void dfs(int node, vector<vector<int>>& adjacent, vector<bool>& visited, 
            bool& isCycle, vector<int>& order, vector<int>& finish, int& time) {
        
        visited[node] = true;
        time++;

        for(auto child : adjacent[node]) {
            if(!visited[child]) {
                dfs(child, adjacent, visited, isCycle, order, finish, time);
            }
            else if(!finish[child]) {
                isCycle = true;
            }
        }

        finish[node] = time;
        order.push_back(node);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacent(numCourses);
        for(auto pre : prerequisites) {
            adjacent[pre[0]].push_back(pre[1]);
        }

        vector<bool> visited(numCourses);
        bool isCycle {false};
        vector<int> order;
        vector<int> finish(numCourses);
        int time {};

        for(int course{}; course < numCourses; ++course) {
            if(!visited[course]) {
                dfs(course, adjacent, visited, isCycle, order, finish, time);
            }
        }
        return (isCycle)? vector<int>{} : order;
    }
};

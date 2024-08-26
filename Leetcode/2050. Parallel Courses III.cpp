class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adjacent(n);
        vector<int> inDegree(n);
        for(auto edge : relations) {
            edge[0]--;
            edge[1]--;
            adjacent[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        queue<int> courses;
        vector<int> maxParentTime(n);
        int answer{};
        for(int course{}; course < n; ++course) {
            if(!inDegree[course]) {
                courses.push(course);
                maxParentTime[course] = time[course];
                answer = max(answer,  time[course]);
            }
        }

        while(!courses.empty()) {
            int size = courses.size();
            while(size--) {
                int current = courses.front();
                courses.pop();

                for(int child : adjacent[current]) {
                    maxParentTime[child] = max(maxParentTime[child], time[current]);

                    if(!--inDegree[child]) {
                        courses.push(child);
                        time[child] += maxParentTime[child];
                        answer = max(answer,  time[child]);
                    }
                }
            }
        }

        return answer;
    }
};

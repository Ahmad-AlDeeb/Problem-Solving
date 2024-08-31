class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        vector<vector<int>> adjacent(numCourses);
        for(auto pre : prerequisites) {
            adjacent[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int> courses;
        for(int i{}; i < numCourses; ++i) {
            if(!inDegree[i]) {
                courses.push(i);
            }
        }

        int finishedCount{};
        while(!courses.empty()) {
            int current = courses.front();
            courses.pop();
            finishedCount++;
            for(auto course : adjacent[current]) {
                if(!--inDegree[course]) {
                    courses.push(course);
                }
            }
        }
        return finishedCount == numCourses;
     }
};

class Solution {
public:
    /**
     * @param n: the number of courses
     * @param relations: the relationship between all courses
     * @return: ehe minimum number of semesters required to complete all courses
     */
    int minimumSemesters(int n, vector<vector<int>> &relations) {
        vector<int> inDegree(n + 1);
        vector<vector<int>> adjacent(n + 1);
        for(auto relation : relations) {
            adjacent[relation[0]].push_back(relation[1]);
            inDegree[relation[1]]++;
        }

        
        queue<int> courses;
        for(int i{1}; i <= n; ++i) {
            if(!inDegree[i]) {
                courses.push(i);
            }
        }
        
        int semesters{};
        int finishedCourses{};
        for(int size = courses.size(); !courses.empty(); ++semesters, size = courses.size())
            while(size--) {
                int current = courses.front();
                courses.pop();

                finishedCourses++;

                for(auto course : adjacent[current]) {
                    if(!--inDegree[course]) {
                        courses.push(course);
                    }
                }
            }
        cout << finishedCourses;
        return (finishedCourses == n)? semesters : -1;
    }
};

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeros{};
        int ones{};

        queue<int> stud, sand;
        for(int i{}; i<students.size(); i++) {
            if(students[i]) ones++;
            else            zeros++;

            stud.push(students[i]);
            sand.push(sandwiches[i]);
        }


        while(!sand.empty()) {
            if(stud.front() == sand.front()) {
                if(stud.front()) ones--;
                else             zeros--;

                stud.pop();
                sand.pop();
            }
            else {
                if(sand.front() && !ones || !sand.front() && !zeros)
                    break;
                else {
                    stud.push(stud.front());
                    stud.pop();
                }
            }
        }

        return stud.size();
    }
};

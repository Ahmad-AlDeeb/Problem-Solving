class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        unordered_map<int, unordered_set<int>> visited;
        visited.emplace(0,0);

        queue<pair<int,int>> jars;
        jars.emplace(0,0);

        for(int size = jars.size(); !jars.empty(); size = jars.size())
            while(size--) {
                auto current = jars.front();
                int jar1 = current.first;
                int jar2 = current.second;
                jars.pop();

                if(jar1 + jar2 == target) {
                    return true;
                }

                pair<int,int> state1 {x, jar2};
                pair<int,int> state2 {jar1, y};

                pair<int,int> state3 {0, jar1 + jar2};
                if(jar2 == y) {
                    state3 = current;
                }
                else if(y < jar1 + jar2) {
                    state3.second = y;
                    state3.first = jar1 + jar2 - y;
                }

                pair<int,int> state4 {jar1 + jar2, 0};
                if(jar1 == x) {
                    state4 = current;
                }
                else if(x < jar1 + jar2) {
                    state4.first = x;                    
                    state4.second = jar1 + jar2 - x;
                }

                pair<int,int> state5 {0, jar2};
                pair<int,int> state6 {jar1, 0};

                vector<pair<int,int>> states {state1, state2, state3, state4, state5, state6};

                for(auto state : states) {
                    if(visited[state.first].insert(state.second).second == true) { 
                        jars.push(state);
                    }   
                }
            }
        
        return false;
    }
};

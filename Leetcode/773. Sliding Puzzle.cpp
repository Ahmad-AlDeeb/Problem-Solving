class Solution {
    const vector<int> di{1,-1, 0, 0};
    const vector<int> dj{0, 0, 1,-1};

    bool valid(int i, int j) {
        return (i >= 0 && i < 2) and (j >= 0 && j < 3);
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        const vector<vector<int>> target{{1,2,3}, {4,5,0}};                

        set<vector<vector<int>>> visited;
        visited.insert(board);

        queue<vector<vector<int>>> states;
        states.push(board);

        for(int level{}, size = states.size(); !states.empty(); ++level, size = states.size())
            while(size--) {
                auto current = states.front();
                states.pop();
                
                if(current == target) {
                    return level;
                }

                int zero_i,zero_j;
                for(int i{}; i < 2; ++i)
                    for(int j{}; j < 3; ++j)
                        if(current[i][j] == 0) {
                            zero_i = i;
                            zero_j = j; 
                        }

                for(int dir{}; dir < 4; ++dir) {
                    int i = zero_i + di[dir];
                    int j = zero_j + dj[dir];

                    // You can swap twice instead of copying to increase efficiency
                    auto state = current;

                    if(valid(i, j)) {
                        swap(state[zero_i][zero_j], state[i][j]);

                        if(visited.insert(state).second == true) {
                            states.push(state);
                        }
                    }
                }
            }
        return -1;
    }
};

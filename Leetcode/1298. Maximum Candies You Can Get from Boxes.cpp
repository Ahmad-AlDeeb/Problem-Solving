class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = candies.size();
        vector<bool> found(n);
        vector<bool> open(n);
        queue<int> boxes;

        for(auto box : initialBoxes) { 
            if(status[box]) {
                open[box] = true;
            }
            found[box] = true;
            boxes.push(box);
        }

        for(int size = boxes.size(); !boxes.empty(); size = boxes.size())
            while(size--) {
                int current = boxes.front();
                boxes.pop();

                if(open[current]) {
                    
                    for(auto key : keys[current]) {
                        if(!open[key]) {
                            if(found[key]) {
                                open[key] = true;
                            }
                            if(!status[key]) {
                                status[key] = 1;
                                boxes.push(key);
                            }
                        }
                    }

                    for(auto box : containedBoxes[current]) {
                        if(!open[box]) {
                            if(status[box]) {
                                open[box] = true;
                            }
                            if(!found[box]) {
                                found[box] = true;
                                boxes.push(box);
                            }
                        }
                    }
                }
            }


        int answer{};
        for(int i{}; i < n; ++i) {
            if(open[i]) {
                answer += candies[i];
            }
        }
        return answer;
    }
};

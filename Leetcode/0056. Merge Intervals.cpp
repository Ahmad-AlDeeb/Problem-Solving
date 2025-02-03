class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> mergedIntervals {intervals.front()};

        for(int i{1}; i < intervals.size(); ++i) {
            vector<int> &lastInterval = mergedIntervals.back();
            vector<int> curInterval = intervals[i];

            if(curInterval[0] <= lastInterval[1]) {
                if(curInterval[1] > lastInterval[1]) {
                    lastInterval[1] = curInterval[1];
                }
            }
            else {
                mergedIntervals.push_back(curInterval);
            }
        }

        return mergedIntervals;
    }
};

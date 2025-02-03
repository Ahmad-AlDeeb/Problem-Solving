class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int answer{};

        vector<int> lastInterval = intervals.front();
        for(int i{1}; i < intervals.size(); ++i) {            
            vector<int> curInterval = intervals[i];

            if(curInterval[0] < lastInterval[1]) {
                answer++;

                if(curInterval[1] < lastInterval[1]) {
                    lastInterval = curInterval;
                }
            }
            else {
                lastInterval = curInterval;
            }
        }

        return answer;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();

        for(int i{}; i < n; ++i) {
            cars.emplace_back(position[i], speed[i]);
        }
        sort(cars.rbegin(), cars.rend());

        int fleetCount{1};
        int curPosition = cars.front().first;
        int curSpeed = cars.front().second;

        for(int i{1}; i < n; ++i) {
            int nexPosition = cars[i].first;
            int nexSpeed = cars[i].second;

            double timeNeededForNex = (curPosition - nexPosition) / (double) (nexSpeed - curSpeed);
            double timeNeededForCur = (target - curPosition)     / (double) curSpeed;
            
            if(timeNeededForNex <= 0 || timeNeededForNex > timeNeededForCur) {
                fleetCount++;
                curPosition = nexPosition;
                curSpeed = nexSpeed;
            }
        }

        return fleetCount;
    }
};

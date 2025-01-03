class Solution {


    double calcDistance(vector<int> point) {
        int x = point[0];
        int y = point[1];
        return sqrt(pow(x, 2) + pow(y, 2));
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, vector<int>>> distances;
        for(auto point : points) {
            distances.emplace_back(calcDistance(point), point);
        }
        sort(distances.begin(), distances.end());

        vector<vector<int>> closestPoints;
        for(int i{}; i < k; ++i) {
            closestPoints.push_back(distances[i].second);
        }
        return closestPoints;
    }
};

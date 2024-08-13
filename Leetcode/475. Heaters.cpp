class Solution {
public:
    bool valid(vector<int>& houses, vector<int>& heaters, int radius) {
        for(auto house : houses) {
            auto it = upper_bound(heaters.begin(), heaters.end(), house);

            if(it != heaters.end()) {
                int right_heater = *it;
                
                if(it != heaters.begin()) {
                    int left_heater = heaters[it - heaters.begin() - 1];
                    if(house > left_heater + radius && house < right_heater - radius) {
                        return false;
                    }
                }
                else {
                    if(house < right_heater - radius) {
                        return false;
                    }
                }
            }
            else {
                int left_heater = heaters[it - heaters.begin() - 1];
                if(house > left_heater + radius) {
                    return false;
                }
            }
        }

        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        
        int answer{};
        int l{}, r{1000000000};
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(valid(houses, heaters, mid)) {
                r = mid - 1;
                answer = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return answer;
    }
};

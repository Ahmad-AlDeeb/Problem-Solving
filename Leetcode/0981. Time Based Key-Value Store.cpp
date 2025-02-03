bool customComparator(const pair<int, string>& lhs, const pair<int, string>& rhs) {
    return lhs.first < rhs.first;
}

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> keyToVal;
public:
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        keyToVal[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> &values = keyToVal[key];
        if(values.empty() || values.front().first > timestamp) {
            return "";
        }
        
        auto it = upper_bound(values.begin(), values.end(), make_pair(timestamp, ""), customComparator);
        --it;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

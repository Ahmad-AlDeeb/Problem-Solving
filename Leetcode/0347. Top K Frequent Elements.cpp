class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto num : nums) {
            if(mp.find(num) == mp.end()) {
                mp[num] = 1;
            }
            else {
                mp[num]++;
            }
        }

        vector<pair<int,int>> elements;
        for(auto p : mp) {
            elements.emplace_back(p.second, p.first);
        }
        sort(elements.begin(), elements.end(), greater<>());

        vector<int> answer;
        for(int i{}; i<k; i++) {
            answer.push_back(elements[i].second);
        }
        return answer;
    }
};

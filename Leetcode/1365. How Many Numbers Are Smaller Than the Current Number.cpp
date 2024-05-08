class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int> count;
        for(auto num : nums) 
            count[num]++;
        
        vector<pair<int,int>> pairs;
        for(auto pair : count)
            pairs.push_back(pair);


        vector<int> freq (nums.size());
        for(int i{}; i<pairs.size(); i++)
            freq[i] = pairs[i].second;
        for(int i{1}; i<nums.size(); i++)
            freq[i] += freq[i-1];

        map<int,int> m;
        m[pairs.front().first] = 0;
        for(int i{1}; i<pairs.size(); i++)
            m[pairs[i].first] = freq[i-1];
        
        vector<int> ans (nums.size());
        for(int i{}; i<nums.size(); i++)
            ans[i] = m[nums[i]];
        return ans;
    }
};

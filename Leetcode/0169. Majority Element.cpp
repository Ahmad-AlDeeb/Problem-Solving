class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> frequency;
        for(auto num : nums)
            frequency[num]++;
        
        pair<int,int> max = *frequency.begin();
        for(auto current : frequency) {
            if(current.second > max.second)
                max = current;
        }
        
        return max.first;
    }
};

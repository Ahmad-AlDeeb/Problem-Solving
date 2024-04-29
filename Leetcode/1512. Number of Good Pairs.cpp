class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> count;
        

        for(int i{}; i<nums.size(); i++) 
            count[nums[i]]++;

        int answer{};
        for(auto pair : count) {
            int n = pair.second-1;
            answer += (n+n*n)/2;
        }
            
        return answer;
    }
};

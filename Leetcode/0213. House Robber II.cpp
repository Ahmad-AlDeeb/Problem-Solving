class Solution {
public:
    map<pair<int,int>, int> cache;
    int rec(vector<int>& nums, int start, int end) {
        // Base case
        if(start > end)
            return 0;

        // Sub-problem
        if(cache.find({start,end}) != cache.end())
            return cache[{start, end}];
        

        return cache[{start, end}] = max(rec(nums, start+1, end), rec(nums, start+2, end) + nums[start]);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums.front();

        return max(rec(nums,0,n-2), rec(nums,1,n-1));
    }
};

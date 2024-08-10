class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int size = nums.size();
        for(int i{size-1}; i>=2; i--) {
            int a{nums[i]}, b{nums[i-1]}, c{nums[i-2]};
            if(a < b + c)
                return a+b+c;
        }
        return 0;
    }
};

class Solution {
    vector<int> nums;
    unordered_set<int> selectedIndex;
    set<vector<int>> unique_perms;
    vector<int> permutation;
    int n;

    void permutate(int i) {
        if(i == n) {
            unique_perms.insert(permutation);
            return;
        }

        for(int j{}; j < n; ++j) {
            if(!selectedIndex.count(j)) {
                selectedIndex.insert(j);
                permutation.push_back(nums[j]);

                permutate(i + 1);
                
                permutation.pop_back();
                selectedIndex.erase(j);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums_) {
        nums = nums_;
        n = nums.size();
        permutate(0);
        
        vector<vector<int>> answer;
        for(auto perm : unique_perms)
            answer.push_back(perm);
        return answer;
    }
};

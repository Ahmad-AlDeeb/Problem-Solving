class Solution {
    vector<int> nums;
    unordered_set<int> selected;
    vector<vector<int>> answer;
    vector<int> permutation;

    void permutate(int i) {
        if(i == nums.size()) {
            answer.push_back(permutation);
            return;
        }

        for(auto num : nums) {
            if(!selected.count(num)) {
                selected.insert(num);
                permutation.push_back(num);

                permutate(i + 1);

                selected.erase(num);
                permutation.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums_) {
        nums = nums_;
        permutate(0);
        return answer;
    }
};

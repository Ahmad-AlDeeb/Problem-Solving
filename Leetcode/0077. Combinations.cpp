class Solution {
    vector<vector<int>> combinations;
    
    void buildCombinations(int n, int k, vector<int>& curCombination, int value) {
        if(curCombination.size() == k) {
            combinations.push_back(curCombination);
            return;
        }
        
        if(value > n) {
            return;
        }

        buildCombinations(n, k, curCombination, value + 1);
        
        curCombination.push_back(value);
        buildCombinations(n, k, curCombination, value + 1);
        curCombination.pop_back();
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curCombination;
        buildCombinations(n, k, curCombination, 1);

        return combinations;
    }
};

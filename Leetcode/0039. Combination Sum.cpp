class Solution {
    set<vector<int>> answer;

    void calcAnswer(vector<int>& candidates, int target, int index, int sum, vector<int>& combination) {
        if(sum > target) {
            return;
        }
        if(index >= candidates.size()) {
            if(sum == target)
                answer.insert(combination);
            return;
        }


        calcAnswer(candidates, target, index + 1, sum, combination);

        int curCandidate = candidates[index];
        
        combination.push_back(curCandidate);
        calcAnswer(candidates, target, index + 1, sum + curCandidate, combination);
        calcAnswer(candidates, target, index    , sum + curCandidate, combination);
        combination.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        sort(candidates.rbegin(), candidates.rend());
        
        calcAnswer(candidates, target, 0, 0, combination);
        return vector<vector<int>>(answer.begin(), answer.end());
    }
};

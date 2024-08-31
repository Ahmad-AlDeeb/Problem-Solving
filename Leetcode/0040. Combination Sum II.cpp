class Solution {
public:
    void calc(vector<int> &candidates, vector<vector<int>> &result, int i, vector<int> temp, int target) {
        if(target == 0) {
            result.push_back(temp);
            return;
        }
        if(target < 0 || i == candidates.size()) 
            return;     

        int current = candidates[i];
        
        temp.push_back(current);
        calc(candidates, result, i+1, temp, target-current);
        temp.pop_back();

        while(i < candidates.size()-1 && candidates[i]==candidates[i+1])
            i++;
        
        calc(candidates, result, i+1, temp, target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;

        calc(candidates, result, 0, temp, target);

        return result;
    }

    
};

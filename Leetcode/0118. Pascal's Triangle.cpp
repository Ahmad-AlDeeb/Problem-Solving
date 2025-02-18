class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal {{1}};
        if(numRows == 1) {
            return pascal;
        }
        
        pascal.push_back({1,1});
        if(numRows == 2) {
            return pascal;
        }

        for(int r{3}; r <= numRows; ++r) {
            vector<int> lastRow = pascal.back();
            vector<int> newRow(lastRow.size() + 1);
            newRow.front() = newRow.back() = 1;
            for(int i{1}; i < newRow.size() - 1; ++i) {
                newRow[i] = lastRow[i - 1] + lastRow[i];
            }
            pascal.push_back(newRow);
        }
        return pascal;
    }
};

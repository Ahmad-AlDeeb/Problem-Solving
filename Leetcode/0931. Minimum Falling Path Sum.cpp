int const MAX_N = 100 + 1;

class Solution {
    vector<vector<int>> matrix;
    int n;
    vector<vector<int>> cache;
  
    int getMinSum(int i, int j) {
        if(j < 0 || j >= n) {
            return INT_MAX / 2;
        }
        if(i == n - 1) {
            return matrix[i][j];
        }
        
        int &answer = cache[i][j];
        if(answer != INT_MAX) {
            return answer;
        }

        int leftOption = getMinSum(i + 1, j - 1);
        int middleOption = getMinSum(i + 1, j);
        int rightOption = getMinSum(i + 1, j + 1);

        return answer = min({leftOption, middleOption, rightOption}) + matrix[i][j];
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix_) {
        matrix = matrix_;
        n = matrix.size();
        
        vector<vector<int>> cache_(n, vector<int>(n, INT_MAX));
        cache = cache_;

        int answer{INT_MAX};
        for(int j{}; j < n; ++j) {
            answer = min(answer, getMinSum(0, j));
        }
        return answer;
    }
};

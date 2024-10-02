const int MAX_M = 300 + 1;
const int MAX_N = 300 + 1;

class Solution {
    int m, n;
    vector<vector<char>> matrix;
    int cache[MAX_M][MAX_N];

    bool isValid(int i, int j) {
        return i < m && j < n && matrix[i][j] == '1';
    }

    int getMaxSquare(int i, int j) {
        if(!isValid(i, j)) {
            return 0;
        }

        int &count = cache[i][j];
        if(count != -1) {
            return count;
        }
        count = 1;

        int rightCount    = getMaxSquare(i    , j + 1);
        int diagonalCount = getMaxSquare(i + 1, j + 1);
        int downCount     = getMaxSquare(i + 1, j    );

        return count += min({rightCount, diagonalCount, downCount});
    }


public:
    int maximalSquare(vector<vector<char>>& matrix_) {
        matrix = matrix_;
        m = matrix.size();
        n = matrix[0].size();
        memset(cache, -1, sizeof(cache));
        
        int maxCount{};
        for(int i{}; i < m; ++i) {
            for(int j{}; j < n; ++j) {
                maxCount = max(maxCount, getMaxSquare(i, j));
            }
        }
        return pow(maxCount, 2);
    }
};

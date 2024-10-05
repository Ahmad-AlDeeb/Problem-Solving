struct Cell {int x, y;};

class Solution {
    vector<vector<string>> answer;
    vector<bool> visitedColumns;
    vector<vector<int>> cellAttackCount;
    vector<string> board;
    int n;

    void mark(int row, int col) {
        board[row][col] = 'Q';
        
        visitedColumns[col] = true;

        for(int i{row}, j{col}; i < n && j < n; ++i, ++j) {
            cellAttackCount[i][j]++;
        }
        for(int i{row}, j{col}; i < n && j >= 0; ++i, --j) {
            cellAttackCount[i][j]++;
        }
    }
    void unmark(int row, int col) {
        board[row][col] = '.';

        visitedColumns[col] = false;
        
        for(int i{row}, j{col}; i < n && j < n; ++i, ++j) {
            cellAttackCount[i][j]--;
        }
        for(int i{row}, j{col}; i < n && j >= 0; ++i, --j) {
            cellAttackCount[i][j]--;
        }
    }

    void tryColumn(int row = 0) {
        if(row >= n) {
            answer.push_back(board);
            return;
        }

        for(int col{}; col < n; ++col) {
            if(!visitedColumns[col] && !cellAttackCount[row][col]) {
                mark(row, col);
                tryColumn(row + 1);
                unmark(row, col);
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n_) {
        n = n_;
        board.resize(n, string(n, '.'));
        visitedColumns.resize(n, false);
        cellAttackCount.resize(n, vector<int>(n));

        tryColumn();
        return answer;
    }
};

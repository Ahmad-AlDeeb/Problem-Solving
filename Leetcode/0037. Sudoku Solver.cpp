    vector<pair<int, int>> blockStarts = {
        {0, 0}, {0, 3}, {0, 6},  // Top row of 3x3 blocks
        {3, 0}, {3, 3}, {3, 6},  // Middle row of 3x3 blocks
        {6, 0}, {6, 3}, {6, 6}   // Bottom row of 3x3 blocks
    };

class Solution {
    vector<vector<char>> board;
    vector<vector<char>> validBoard;

    bool foundDuplicateInBlock(char digit, pair<int, int> blockStart) {
        int startRow = blockStart.first;
        int startCol = blockStart.second;
        int endRow = startRow + 2;
        int endCol = startCol + 2;

        for(int i{startRow}; i <= endRow; ++i) {
            for(int j{startCol}; j <= endCol; ++j) {
                if(board[i][j] == digit)
                    return true;
            }
        }
        return false;
    }
    
    bool isInBlock(int r, int c, pair<int,int> blockStart) {
        int startRow = blockStart.first;
        int startCol = blockStart.second;
        int endRow = startRow + 2;
        int endCol = startCol + 2;
        
        return (r >= startRow && r <= endRow) && (c >= startCol && c <= endCol);
    }
    
    bool isValid(int r, int c, char digit) {
        for(int i{}; i < 9; ++i) {
            if(board[r][i] == digit || board[i][c] == digit)
                return false;
        }

        for(auto block : blockStarts) {
            if(isInBlock(r, c, block) && foundDuplicateInBlock(digit, block))
                return false;
        }

        return true;
    }

    void tryDigits(int r, int c) {
        if(r == 8 && c == 9) {
            validBoard = board;
            return;
        }
        if(c == 9) {
            r++;
            c = 0;
        }
        if(board[r][c] != '.') {
            tryDigits(r, c + 1);
            return;
        }

        for(char digit{'1'}; digit <= '9'; ++digit) {
            if(isValid(r, c, digit)) {
                board[r][c] = digit;
                tryDigits(r, c + 1);
                board[r][c] = '.';
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board_) {
        board = board_;
        tryDigits(0, 0);
        board_ = validBoard;
    }
};

class Solution {
public:
    bool isValidBlock(vector<vector<char>>& board, int start_i, int start_j) {
        vector<bool> vis(10);

        for(int i{start_i}, row_count{3}; row_count; i++, row_count--) {
            for(int j{start_j}, col_count{3}; col_count; j++, col_count--) {
                char cell = board[i][j];
                if(cell != '.') {
                    if(vis[cell-'0']) {
                        return false;
                    }
                    else {
                        vis[cell-'0'] = true;
                    }
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // Check horizontally.
        for(int i{}; i<9; i++) {
            vector<bool> vis(10);
            
            for(int j{}; j<9; j++) {
                char cell = board[i][j];
                
                if(cell != '.') {
                    if(vis[cell]) {
                        return false;
                    }
                    else {
                        vis[cell] = true;
                    }
                }
            }
        }

        // Check vertically.
        for(int j{}; j<9; j++) {
            vector<bool> vis(10);

            for(int i{}; i<9; i++) {
                char cell = board[i][j];
                
                if(cell != '.') {
                    if(vis[cell-'0']) {
                        return false;
                    }
                    else {
                        vis[cell-'0'] = true;
                    }
                }
            }
        }

        // Check blocks.
        for(int i{}; i<9; i+=3) {
            for(int j{}; j<9; j+=3) {
                if(!isValidBlock(board, i, j)) {
                    return false;
                }
            }
        }


        return true;
    }
};

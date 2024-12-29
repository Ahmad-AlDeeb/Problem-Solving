class Solution {
  bool checkRows(vector<vector<char>>& board) {
      for(int i{}; i < 9; ++i) {
      unordered_map<char, bool> exist;

      for(int j{}; j < 9; ++j) {
        if(board[i][j] == '.') {
        	continue;
        }
        
        if(exist[board[i][j]]) {
          return false;
        }
        exist[board[i][j]] = true;
      }
    }
    return true;
  }
  
    bool checkCols(vector<vector<char>>& board) {
      for(int i{}; i < 9; ++i) {
      unordered_map<char, bool> exist;

      for(int j{}; j < 9; ++j) {
        if(board[j][i] == '.') {
        	continue;
        }
      
        if(exist[board[j][i]]) {
          return false;
        }
        exist[board[j][i]] = true;
      }
    }
    return true;
  }
  
  bool isBoxValid(vector<vector<char>>& board, int rowStart, int colStart) {
  	unordered_map<char, bool> exist;

    for(int i{rowStart}; i < rowStart+3; ++i) {
    	
      
        for(int j{colStart}; j < colStart+3; ++j) {
        if(board[i][j] == '.') {
        	continue;
        }
      
       if(exist[board[i][j]]) {
          return false;
        }
        exist[board[i][j]] = true;
      }
    }
    return true;
  }


public:
    bool isValidSudoku(vector<vector<char>>& board) {
		
      for(int rowStart{}; rowStart < 9; rowStart += 3) {
      	for(int colStart{}; colStart < 9; colStart += 3) {
        	if(!isBoxValid(board, rowStart, colStart)) {
          	return false;
          }
        }
      }
      
      return checkRows(board) && checkCols(board);
    }
};

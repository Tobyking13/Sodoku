#include "constants.h"
#include "update_board.h"
#include <vector>

using std::vector;

void eraseCell(vector<vector<int>>& board, int row, int col)
{
  for(int i = 0; i < LEN; ++i) {
    for(int j = 0; j < LEN; ++j) {
      if (i == row && j == col) 
        board[i][j] = 0;
    }
  }
}
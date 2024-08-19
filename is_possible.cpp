#include "constants.h"

#include <iostream>
#include <vector>

using std::vector;

bool isPossible(vector<vector<int>>& board, int row, int col, int val) 
{
  for (int i = 0; i <= LEN-1; ++i) {
    if (board[row][i] == val) return false;
  }
  for (int i = 0; i <= LEN-1; ++i) {
    if (board[i][col] == val)  return false;
  }

  int startRow = row - row % 3;
  int startCol = col - col % 3;

  for (int i = startRow; i < startRow + 3; ++i) {
    for (int j = startCol; j < startCol + 3; ++j) {
      if (board[i][j] == val) return false;
    }
  }
  return true;
}

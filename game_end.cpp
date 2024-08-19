#include "constants.h"
#include <vector>

using std::vector;

bool gameEnd(vector<vector<int>>& board) 
{
  for (int i = 0; i < LEN; ++i) {
    for (int j = 0; j < LEN; ++j) {
      if (board[i][j] == 0) return false;
    }
  }
  return true;
}
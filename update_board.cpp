#include "constants.h"

#include<vector>
#include<iostream>

using std::vector;

void updateBoard(vector<vector<int>>& board, int row, int col, int val) 
{
  for (int i = 0; i <= LEN ; ++i) {
    for (int j = 0; j <= LEN; ++j) {
      if (row == i && col == j){
        board[i][j] = val;
      }
    }
  }
}
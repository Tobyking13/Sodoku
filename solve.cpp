#include "constants.h"
#include "is_possible.h"
#include <iostream>
#include <set>
#include <vector>

using std::set;
using std::vector;

bool solve(vector<vector<int>> &board)
{
  for (int i = 0; i < LEN; ++i)
  {
    for (int j = 0; j < LEN; ++j)
    {
      if (board[i][j] == 0)
      {
        for (int l = 1; l <= LEN; ++l)
        {
          if (isPossible(board, i, j, l))
          {
            board[i][j] = l;
            if (solve(board))
              return true;
            board[i][j] = 0;
          }
        }
        return false;
      }
    }
  }
  return true;
}

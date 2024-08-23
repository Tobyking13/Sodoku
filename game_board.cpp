#include "constants.h"
#include "user_move.h"
#include "game_board.h"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool GameBoard::isCellOccupied(int row, int col) const
{
  return board[row][col] != 0;
}

bool GameBoard::isPossible(int row, int col, int val, History& userHistory, UserMoves& moves)
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
  GameBoard::row = row;
  GameBoard::col = col;
  GameBoard::val = val;
  GameBoard::updateCell(userHistory, moves);
  return true;
}

void GameBoard::updateCell(History& userHistory, UserMoves& moves) // add userHistory
{
  moves.row = row;
  moves.col = col;
  moves.previousValue = board[row][col];
  moves.newValue = val;
  board[row][col] = val;

  userHistory.moves.push_back(moves);
  
  cout << "User move history..." << endl;
  cout << endl;
  for(UserMoves& move : userHistory.moves) {
    cout << move << endl;
  }
}
  
void GameBoard::deleteCell(int row, int col, History& userHistory, UserMoves& moves)
{
  GameBoard::row = row;
  GameBoard::col = col;
  GameBoard::val = 0;
  GameBoard::updateCell(userHistory, moves);
}

bool GameBoard::autoSolve(History& userHistory, UserMoves& moves)
{
  for (int i = 0; i < LEN; ++i)
  {
    for (int j = 0; j < LEN; ++j)
    {
      if (board[i][j] == 0)
      {
        for (int l = 1; l <= LEN; ++l)
        {
          if (GameBoard::isPossible(i, j, l, userHistory, moves))
          {
            board[i][j] = l;
            if (autoSolve(userHistory, moves))
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

void GameBoard::printBoard() const
{
  cout << "\n";
  for (int row = 0; row < LEN; ++row) {
    for (int col = 0; col < LEN; ++col) {
      cout << board[row][col] << " ";
      if ((col + 1) % 3 == 0 && col < LEN - 1) {
        cout << "| ";
      } 
    }
    cout << endl;
    if ((row + 1) % 3 == 0 && row < LEN - 1) {
      cout << "------+-------+------" << endl;
    }
  }
  cout << endl;
}

bool GameBoard::gameEnd() const
{
  for (int i = 0; i < LEN; ++i) {
    for (int j = 0; j < LEN; ++j) {
      if (board[i][j] == 0) return false;
    }
  }
  return true;
}



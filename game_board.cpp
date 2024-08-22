#include "constants.h"
#include "user_move.h"
#include "game_board.h"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool GameBoard::isCellOccupied(int row, int col) 
{
  return board[row][col] != 0;
}

bool GameBoard::isPossible(int row, int col, int val)
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
  return true;
}

void GameBoard::updateCell() // add userHistory
{
  board[row][col] = val;
}
  
void GameBoard::deleteCell(int row, int col) 
{
  GameBoard::row = row;
  GameBoard::col = col;
  GameBoard::val = 0;
  GameBoard::updateCell();
}

bool GameBoard::autoSolve()
{
  for (int i = 0; i < LEN; ++i)
  {
    for (int j = 0; j < LEN; ++j)
    {
      if (board[i][j] == 0)
      {
        for (int l = 1; l <= LEN; ++l)
        {
          if (GameBoard::isPossible(i, j, l))
          {
            board[i][j] = l;
            if (autoSolve())
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

void GameBoard::printBoard()
{
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

bool GameBoard::gameEnd()
{
  for (int i = 0; i < LEN; ++i) {
    for (int j = 0; j < LEN; ++j) {
      if (board[i][j] == 0) return false;
    }
  }
  return true;
}



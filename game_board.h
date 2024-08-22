#ifndef BOARD_H
#define BOARD_H

#include "constants.h"
#include "user_move.h"

#include <vector>

class GameBoard {
private:
  int row;
  int col;
  int val;
  std::vector<std::vector<int>> board;

public:
  GameBoard(int r, int c, int v) 
    : row(r), col(c), val(v), board(r, std::vector<int>(c, v)) {}

  bool isCellOccupied(int, int);
  bool isPossible(int, int, int);
  void updateCell();
  void deleteCell(int, int);
  bool autoSolve();
  void printBoard(); 
  bool gameEnd();
};

#endif // BOARD_H
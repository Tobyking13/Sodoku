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

  bool isCellOccupied(int, int) const;
  bool isPossible(int, int, int, History&, UserMoves&);
  void updateCell(History&, UserMoves&);
  void deleteCell(int, int, History&, UserMoves&);
  bool autoSolve(History&, UserMoves &);
  void printBoard() const; 
  bool gameEnd() const;
};

#endif // BOARD_H
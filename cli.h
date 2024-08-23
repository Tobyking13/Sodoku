#ifndef CLI_H
#define CLI_H

#include "game_board.h"

class CLI {
private:
  int row;
  int col;
  int val;

public:
  int mode;
  void init(const GameBoard&);
  void gameStart();
  void enterCell(GameBoard&, History&, UserMoves&);
  void deleteCell(GameBoard&, History&, UserMoves&);
  bool gameComplete(const GameBoard&);
};

#endif // CLI_H
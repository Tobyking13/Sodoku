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
  void init(GameBoard&);
  void gameStart();
  void enterCell(GameBoard&);
  void deleteCell(GameBoard&);
  bool gameComplete(GameBoard&);
};

#endif // CLI_H
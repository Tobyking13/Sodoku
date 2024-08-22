#include "constants.h"
#include "user_move.h"
#include "game_board.h"
#include "cli.h"

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  CLI cli;
  GameBoard game(9,9,0);

  cli.init(game);
  
  while (true) {
    cli.gameStart();    
    if (cli.mode == 0) {
      cli.enterCell(game);
    } else if (cli.mode == 1) {
      cli.deleteCell(game);
    } else {
      game.autoSolve();
    }
    game.printBoard();
    if(cli.gameComplete(game))
      break;
  }
  return 0;
}

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
  History userHistory;
  UserMoves moves;
  cli.init(game);
  
  while (true) {
    cli.gameStart();    
    if (cli.mode == 0) {
      cli.enterCell(game, userHistory, moves);
    } else if (cli.mode == 1) {
      cli.deleteCell(game, userHistory, moves);
    } else {
      game.autoSolve(userHistory, moves);
    }
    game.printBoard();
    if(cli.gameComplete(game))
      break;
  }
  return 0;
}

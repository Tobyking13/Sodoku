#include "constants.h"
#include "user_move.h"
#include "game_board.h"

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  int emptyCell = 0;
  int enterOrDel;
  int uInputRow, uInputCol, uInputVal;
  vector<vector<int>> sudokuBoard(LEN, vector<int>(LEN, emptyCell));
  GameBoard game(9,9,0);

  cout << "Sudoku Grid:" << endl;
  game.printBoard();
  
  while (true) {
    do {
      cout << "Press 0 to enter a cell, 1 to delete a cell, or 2 to auto solve:" << endl;
      cin >> enterOrDel;
      if (enterOrDel != 0 && enterOrDel != 1 && enterOrDel != 2)
        cout << "Invalid input! Please enter 0, 1, or 2.\n" << endl;
    } while (enterOrDel != 0 && enterOrDel != 1 && enterOrDel != 2);
    
    if (enterOrDel == 0) {
      do {
        cout << "Please enter row, column, and value (1-9 each):" << endl;
        cin >> uInputRow >> uInputCol >> uInputVal;
        if (uInputRow >= 1 && uInputRow <= LEN && uInputCol >= 1 && uInputCol <= LEN && uInputVal >= 1 && uInputVal <= LEN) {
          uInputRow -= 1;
          uInputCol -= 1;
          if (game.isCellOccupied(uInputRow, uInputCol)) {
            cout << "Cell is already occupied. Please choose an empty cell.\n" << endl;
          } else if (game.isPossible(uInputRow, uInputCol, uInputVal)) {
            game.updateCell();
            game.printBoard();
          } else {
            cout << "Invalid move! This value conflicts with existing numbers.\n" << endl;
          }
        } else {
          cout << "Invalid input! Values must be between 1 and 9.\n" << endl;
        }
      } while (uInputRow >= 1 && uInputRow <= LEN && uInputCol >= 1 && uInputCol <= LEN && uInputVal >= 1 && uInputVal <= LEN);
    } else if (enterOrDel == 1) {
      cout << "Please enter the row and column of the cell to delete (1-9 each):" << endl;
      cin >> uInputRow >> uInputCol;
      if (uInputRow >= 1 && uInputRow <= LEN && uInputCol >= 1 && uInputCol <= LEN) {
        uInputRow -= 1;
        uInputCol -= 1;
        game.deleteCell(uInputRow, uInputCol);
      } else {
        cout << "Invalid input! Row and column must be between 1 and 9.\n" << endl;
      }
    } else {
      game.autoSolve();
    }
    
    game.printBoard();
    
    if (game.gameEnd()) {
      cout << "Well done! You have completed the Sudoku!" << endl;
      break;
    }
  }
  return 0;
}

#include "cli.h"
#include "game_board.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void CLI::init(const GameBoard& game)
{
  cout << "Sudoku Grid:" << endl;
  game.printBoard();
}

void CLI::gameStart() 
{
  int enterOrDel;
  do {
    cout << "Press 0 to enter a cell, 1 to delete a cell, or 2 to auto solve:" << endl;
    cin >> enterOrDel;
    if (enterOrDel != 0 && enterOrDel != 1 && enterOrDel != 2)
      cout << "Invalid input! Please enter 0, 1, or 2.\n" << endl;
  } while (enterOrDel != 0 && enterOrDel != 1 && enterOrDel != 2);
  mode = enterOrDel;
}

void CLI::enterCell(GameBoard& game, History& userHistory, UserMoves& moves)
{
  cout << "Please enter row, column, and value (1-9 each):" << endl;
  cin >> row >> col >> val;
  if (row >= 1 && row <= LEN && col >= 1 && col <= LEN && val >= 1 && val <= LEN) {
    row -= 1;
    col -= 1;
    if (game.isCellOccupied(row, col)) {
      cout << "Cell is already occupied. Please choose an empty cell.\n" << endl;
    } else if (game.isPossible(row, col, val, userHistory, moves)) {
      cout << "\nUpdated board..." << endl;
    } else {
      cout << "Invalid move! This value conflicts with existing numbers.\n" << endl;
    }
  } else {
    cout << "Invalid input! Values must be between 1 and 9.\n" << endl;
  }
}

void CLI::deleteCell(GameBoard& game, History& userHistory, UserMoves& moves) 
{
  cout << "Please enter the row and column of the cell to delete (1-9 each):" << endl;
  cin >> row >> col;
  if (row >= 1 && row <= LEN && col >= 1 && col <= LEN) {
    row -= 1;
    col -= 1;
    game.deleteCell(row, col, userHistory, moves);
  } else {
    cout << "Invalid input! Row and column must be between 1 and 9.\n" << endl;
  }
}

bool CLI::gameComplete(const GameBoard& game) 
{
  if (game.gameEnd()) {
    cout << "Well done! You have completed the Sudoku!" << endl;
    return true;
  }
  else return false;
}
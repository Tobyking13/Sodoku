#include "constants.h"
#include "is_possible.h"
#include "game_end.h"
#include "erase.h"
#include "update_board.h"
#include "solve.h"

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void printBoard(const vector<vector<int>>& board) 
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

int main() {
  int emptyCell = 0;
  int enterOrDel;
  int uInputRow, uInputCol, uInputVal;
  vector<vector<int>> sudokuBoard(LEN, vector<int>(LEN, emptyCell));

  cout << "Sudoku Grid:" << endl;
  printBoard(sudokuBoard);
  
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
          if (sudokuBoard[uInputRow][uInputCol] != 0) {
            cout << "Cell is already occupied. Please choose an empty cell.\n" << endl;
          } else if (isPossible(sudokuBoard, uInputRow, uInputCol, uInputVal)) {
            updateBoard(sudokuBoard, uInputRow, uInputCol, uInputVal);
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
        eraseCell(sudokuBoard, uInputRow, uInputCol);
      } else {
        cout << "Invalid input! Row and column must be between 1 and 9.\n" << endl;
      }
    } else {
      solve(sudokuBoard);
    }
    
    printBoard(sudokuBoard);
    
    if (gameEnd(sudokuBoard)) {
      cout << "Well done! You have completed the Sudoku!" << endl;
      break;
    }
  }
  return 0;
}

#ifndef USER_MOVE_H
#define USER_MOVE_H

#include <vector>
#include <ostream>

struct UserMoves {
  int row;
  int col;
  int previousValue;
  int newValue;
};

struct History {
  std::vector<UserMoves> moves; 
};

inline std::ostream& operator<<(std::ostream& os, const UserMoves& move) {
  os << "Row: " << move.row + 1
     << " Column: " << move.col + 1
     << " Previous move: " << move.previousValue
     << " New Value: " << move.newValue;
  return os;
}

#endif // USER_MOVE_H
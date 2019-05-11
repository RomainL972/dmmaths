#ifndef LEBBADI_TURN_H
#define LEBBADI_TURN_H

#include <vector>

class Turn {
  public:
    Turn(int size);
    void increment();
    int turn() const;

  private:
    std::vector<int> m_turns;
};

#endif

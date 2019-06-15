#ifndef LEBBADI_TURN_H
#define LEBBADI_TURN_H

#include <vector>

class DMMaths;

class TurnManager {
  public:
    TurnManager(DMMaths *parent);
    void setParent(DMMaths *parent);
    DMMaths* getParent() const;
    bool prepare();
    void increment();
    int turn() const;

  private:
    std::vector<int> m_turns;
    DMMaths* m_parent;
};

#endif

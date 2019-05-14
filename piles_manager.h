#ifndef LEBBADI_PILES_MANAGER_H
#define LEBBADI_PILES_MANAGER_H

#define PILES 3

#include <vector>

class Pile;
class Disque;
class Turn;
class Logger;

class PilesManager {
  public:
    PilesManager(int disques, Turn* turn, Logger* logger);
    bool moveDisque(Pile* from, Pile* to);
    int moves() const;
    Pile* operator[](int index) const;
    Disque* disque(int size) const;
    void describe() const;
    int currentTurn() const;

  private:
    std::vector<Pile*> m_piles;
    int m_count;
    Turn *m_turn;
    std::vector<Disque*> m_disques;
    Logger* m_logger;
};

#endif

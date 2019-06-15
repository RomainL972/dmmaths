#ifndef LEBBADI_PILES_MANAGER_H
#define LEBBADI_PILES_MANAGER_H

#define PILES 3

#include <vector>

class Pile;
class Disque;
class DMMaths;

class PilesManager {
  public:
    PilesManager(DMMaths *parent);
    bool prepare();
    bool moveDisque(Pile* from, Pile* to);
    Pile* operator[](int index) const;
    Disque* disque(int size) const;
    void setParent(DMMaths *parent);
    DMMaths* getParent() const;

  private:
    DMMaths* m_parent;
    std::vector<Pile*> m_piles;
    std::vector<Disque*> m_disques;
};

#endif

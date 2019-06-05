#ifndef LEBBADI_PILE_H
#define LEBBADI_PILE_H

#include <stack>
#include <utility>

class Disque;

class Pile {
  public:
    Pile(int index);
    bool addDisque(Disque *disque);
    Disque* removeDisque();
    Disque* topDisque() const;
    bool even() const;
    int index() const;
    bool empty() const;

  private:
    std::stack<std::pair<Disque*, bool> > m_disques;
    int m_index;
};

#endif

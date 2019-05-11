#ifndef LEBBADI_PILE_H
#define LEBBADI_PILE_H

#include <stack>

class Disque;

class Pile {
  public:
    Pile(int index);
    bool addDisque(Disque *disque);
    Disque* removeDisque();
    Disque* topDisque() const;
    bool even() const;
    int index() const;

  private:
    std::stack<Disque*> m_disques;
    bool m_even;
    int m_index;
};

#endif

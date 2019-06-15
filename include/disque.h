#ifndef LEBBADI_DISQUE_H
#define LEBBADI_DISQUE_H

class Pile;

class Disque {
  public:
    Disque(int size, Pile* parent);
    int size() const;
    Pile* parent() const;
    void setParent(Pile* parent);

  private:
    int m_size;
    Pile *m_parent;
};

#endif

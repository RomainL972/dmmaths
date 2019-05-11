#include "disque.h"

Disque::Disque(int size, Pile* parent): m_size(size), m_parent(parent) {
}

int Disque::size() const {
  return m_size;
}

Pile* Disque::parent() const {
  return m_parent;
}

void Disque::setParent(Pile* parent) {
  m_parent = parent;
}

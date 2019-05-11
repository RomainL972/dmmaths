#include "pile.h"
#include "disque.h"

Pile::Pile(int index): m_index(index) {
}

bool Pile::addDisque(Disque *disque) {
  if(!m_disques.empty() && disque->size() > m_disques.top()->size()) return false;
  if(!m_disques.empty() && disque->size()+1 == m_disques.top()->size()) m_even = !m_even;
  else m_even = false;
  m_disques.push(disque);
  disque->setParent(this);
  return true;
}

Disque* Pile::removeDisque() {
  Disque* disque = m_disques.top();
  int lastSize = disque->size();
  m_disques.pop();
  if(m_disques.empty()) m_even = true;
  else if(m_disques.top()->size() == lastSize-1) m_even = !m_even;
  return disque;
}

Disque* Pile::topDisque() const{
  if(m_disques.empty()) return nullptr;
  return m_disques.top();
}

bool Pile::even() const {
  return m_even;
}

int Pile::index() const {
  return m_index;
}

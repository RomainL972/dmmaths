#include "pile.h"
#include "disque.h"
#include <utility>

using namespace std;

Pile::Pile(int index): m_index(index) {
}

bool Pile::addDisque(Disque *disque) {
  bool even;
  if(!empty() && disque->size() > get<0>(m_disques.top())->size()) return false;
  if(!empty() && disque->size()+1 == topDisque()->size()) even = !isEven();
  else even = false;
  m_disques.push(pair<Disque*, bool>(disque, even));
  disque->setParent(this);
  return true;
}

Disque* Pile::removeDisque() {
  Disque* disque = get<0>(m_disques.top());
  m_disques.pop();
  return disque;
}

Disque* Pile::topDisque() const{
  if(m_disques.empty()) return nullptr;
  return get<0>(m_disques.top());
}

bool Pile::isEven() const {
  if(m_disques.empty()) return false;
  return get<1>(m_disques.top());
}

int Pile::index() const {
  return m_index;
}

bool Pile::empty() const {
  return m_disques.empty();
}

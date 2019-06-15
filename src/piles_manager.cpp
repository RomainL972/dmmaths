#include "piles_manager.h"
#include "pile.h"
#include "disque.h"
#include "dmmaths.h"
#include <iostream>

using namespace std;

PilesManager::PilesManager(DMMaths *parent): m_parent(parent) {
  for(int i = 0; i < PILES; i++) {
    m_piles.push_back(new Pile(i));
  }
}

bool PilesManager::prepare() {
  Disque *disque;
  if(!getParent()->getDisques())
    return false;
  for(int i = getParent()->getDisques(); i > 0; i--) {
    disque = new Disque(i, m_piles[0]);
    m_piles[0]->addDisque(disque);
    m_disques.insert(m_disques.begin(), disque);
  }
  return true;
}

bool PilesManager::moveDisque(Pile* from, Pile* to) {
  Disque* disque = from->topDisque();
  if(to->addDisque(disque)){
    from->removeDisque();
    return true;
  }
  return false;
}

Pile* PilesManager::operator[](int index) const {
  if (index < 0 || index >= PILES) return nullptr;
  return m_piles[index];
}

Disque* PilesManager::disque(int size) const {
  return m_disques[size];
}

void PilesManager::setParent(DMMaths *parent) {
  m_parent = parent;
}

DMMaths* PilesManager::getParent() const {
  return m_parent;
}

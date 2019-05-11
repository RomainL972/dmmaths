#include "piles_manager.h"
#include "pile.h"
#include "disque.h"
#include "turn.h"
#include <iostream>

using namespace std;

PilesManager::PilesManager(int disques, Turn* turn): m_count(0), m_turn(turn) {
  for(int i = 0; i < PILES; i++) {
    m_piles.push_back(new Pile(i));
  }
  Disque *disque;
  for(int i = disques; i > 0; i--) {
    disque = new Disque(i, m_piles[0]);
    m_piles[0]->addDisque(disque);
    m_disques.insert(m_disques.begin(), disque);
  }
}

bool PilesManager::moveDisque(Pile* from, Pile* to) {
  Disque* disque = from->topDisque();
  if(to->addDisque(disque)){
    from->removeDisque();
    m_count++;
    m_turn->increment();
    return true;
  }
  return false;
}

int PilesManager::moves() const {
  return m_count;
}

Pile* PilesManager::operator[](int index) const {
  if (index < 0 || index >= PILES) return nullptr;
  return m_piles[index];
}

Disque* PilesManager::disque(int size) const {
  return m_disques[size];
}

void PilesManager::describe() const {
  cout << ((m_piles[0]->topDisque() == nullptr) ? 0 : m_piles[0]->topDisque()->size()) << " "
   << ((m_piles[1]->topDisque() == nullptr) ? 0 : m_piles[1]->topDisque()->size()) << " "
   << ((m_piles[2]->topDisque() == nullptr) ? 0 : m_piles[2]->topDisque()->size()) << endl;
}

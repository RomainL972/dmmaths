#include "turn_manager.h"
#include "dmmaths.h"

TurnManager::TurnManager(DMMaths *parent) : m_parent(parent){

}

void TurnManager::setParent(DMMaths *parent) {
  m_parent = parent;
}

DMMaths* TurnManager::getParent() const {
  return m_parent;
}

bool TurnManager::prepare() {
  if(!getParent()->getDisques())
    return false;
  for(int i = 0; i < getParent()->getDisques(); i++) {
    m_turns.push_back(0);
  }
  increment();
  return true;
}

void TurnManager::increment() {
  m_turns[0]++;
  for(long unsigned int i = 0; i < m_turns.size(); i++) {
    if(m_turns[i] > 1) {
      m_turns[i] -= 2;
      if(i+1!=m_turns.size())
        m_turns[i+1]++;
      else
        m_turns[i] = 1;
    }
  }
}

int TurnManager::turn() const {
  for(long unsigned int i = 0; i < m_turns.size(); i++) {
    if(m_turns[i]) return i;
  }
  return -1;
}

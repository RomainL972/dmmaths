#include "turn.h"

Turn::Turn(int size) {
  for(int i = 0; i < size; i++) {
    m_turns.push_back(0);
  }
  increment();
}

void Turn::increment() {
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

int Turn::turn() const {
  for(long unsigned int i = 0; i < m_turns.size(); i++) {
    if(m_turns[i]) return i;
  }
  return -1;
}

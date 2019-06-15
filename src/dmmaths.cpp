#include "dmmaths.h"
#include "turn_manager.h"
#include "piles_manager.h"
#include "logger.h"
#include "disque.h"
#include "pile.h"

DMMaths::DMMaths() {
  m_counter = 0;
  m_turnManager = new TurnManager(this);
  m_pilesManager = new PilesManager(this);
  m_logger = new Logger();
}

void DMMaths::setTurnManager(TurnManager* manager) {
  m_turnManager = manager;
}

TurnManager* DMMaths::getTurnManager() const {
  return m_turnManager;
}

void DMMaths::setPilesManager(PilesManager* manager) {
  m_pilesManager = manager;
}

PilesManager* DMMaths::getPilesManager() const {
  return m_pilesManager;
}

void DMMaths::setLogger(Logger *logger) {
  m_logger = logger;
}

Logger* DMMaths::getLogger() const {
  return m_logger;
}

void DMMaths::setDisques(int disques) {
  m_disques = disques;
}

int DMMaths::getDisques() const {
  return m_disques;
}

void DMMaths::execute() {
  if(!getDisques())
    return;
  if(!getPilesManager()->prepare()) getLogger()->error("Couldn't prepare piles manager");
  if(!getTurnManager()->prepare()) getLogger()->error("Couldn't prepare turn manager");

  PilesManager manager = *getPilesManager();
  Disque *first = manager[0]->topDisque();
  int turn;
  Pile* dest;
  int target, from;
  bool last = false;

  do {
    turn = getTurnManager()->turn();
    if(turn+1 == getDisques()) {
      if(last) break;
      last = true;
      if(!moveDisque(manager[0], manager[2]))
        getLogger()->error("Couldn't move biggest disque", true);
      if(getTurnManager()->turn()+1 == getDisques()) break;
    }
    else if(turn == 0) {
      from = first->parent()->index();
      target = 2-from;
      if(manager[(from + 1) % PILES]->empty() &&
        manager[(from + 2) % PILES]->empty());
      else if(!manager[(from + 1) % PILES]->empty() &&
        (manager[(from + 2) % PILES]->empty() ||
          manager[(from + 1) % PILES]->topDisque()->size() <
          manager[(from + 2) % PILES]->topDisque()->size()))
            target = 1;
      else target = 2;

      if(first->parent()->isEven()) {
        target = target % 2 + 1;
      }
      dest = manager[(from + target) % PILES];
      if(!moveDisque(first->parent(), dest))
        getLogger()->error("Couldn't move first disque", true);
    }
    else {
      if(!moveDisque(manager.disque(turn)->parent(), manager[(manager.disque(turn)->parent()->index()+1)%PILES]))
        if(!moveDisque(manager.disque(turn)->parent(), manager[(manager.disque(turn)->parent()->index()+2)%PILES]))
          getLogger()->error("Couldn't move disque anywhere", true);
    }
  } while(1);
}

bool DMMaths::moveDisque(Pile* from, Pile* to) {
  bool status = getPilesManager()->moveDisque(from, to);
  if(!status) return false;
  getLogger()->logMove(from->index(), to->index());
  getTurnManager()->increment();
  m_counter++;
  return status;
}

void DMMaths::setCounter(unsigned long long counter) {
  m_counter = counter;
}

unsigned long long DMMaths::getCounter() const {
  return m_counter;
}

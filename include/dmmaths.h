#ifndef LEBBADI_DMMATHS_H
#define LEBBADI_DMMATHS_H

class TurnManager;
class PilesManager;
class Logger;
class Pile;

class DMMaths {
public:
  DMMaths();
  void setTurnManager(TurnManager *manager);
  TurnManager* getTurnManager() const;
  void setPilesManager(PilesManager* manager);
  PilesManager* getPilesManager() const;
  void setLogger(Logger* logger);
  Logger* getLogger() const;
  void setDisques(int disques);
  int getDisques() const;
  void execute();
  bool moveDisque(Pile *from, Pile* to);
  void setCounter(unsigned long long counter);
  unsigned long long getCounter() const;

private:
  TurnManager* m_turnManager;
  PilesManager* m_pilesManager;
  Logger* m_logger;
  int m_disques;
  unsigned long long m_counter;
};

#endif

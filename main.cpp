#include <iostream>
#include <string>
#include <limits.h>  // for INT_MAX
#include "pile.h"
#include "disque.h"
#include "piles_manager.h"
#include "turn.h"
#include "logger.h"

using namespace std;

int main(int argc, char const *argv[]) {
  Logger logger("log.txt");
  if(argc < 2)
    logger.error("No argument", true);
  char *p;
  int disques;

  long conv = strtol(argv[1], &p, 10);

  if (*p != '\0' || conv > INT_MAX)
    logger.error("Argument isn't a good number", true);
  disques = conv;

  Turn turns(disques);
  PilesManager manager(disques, &turns);
  logger.setPilesManager(&manager);

  Disque *first = manager[0]->topDisque();
  int turn;
  Pile* dest;
  int target, from;
  bool last = false;
  do {
    turn = turns.turn();
    logger.logState();
    if(turn+1 == disques) {
      if(last) break;
      last = true;
      if(!manager.moveDisque(manager[0], manager[2])) logger.error("Couldn't move biggest disque", true);
      if(turns.turn()+1 == disques) break;
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

      if(first->parent()->even()) {
        target = target % 2 + 1;
      }
      dest = manager[(from + target) % PILES];
      if(!manager.moveDisque(first->parent(), dest))
        logger.error("Couldn't move first disque", true);
    }
    else {
      if(!manager.moveDisque(manager.disque(turn)->parent(), manager[(manager.disque(turn)->parent()->index()+1)%PILES]))
        if(!manager.moveDisque(manager.disque(turn)->parent(), manager[(manager.disque(turn)->parent()->index()+2)%PILES]))
          logger.error("Couldn't move disque anywhere", true);
    }
  } while(1);

  logger.success(manager.moves());
  return EXIT_SUCCESS;
}

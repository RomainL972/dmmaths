#include <iostream>
#include <string>
#include <limits.h>  // for INT_MAX
#include "pile.h"
#include "disque.h"
#include "piles_manager.h"
#include "turn.h"

using namespace std;

int main(int argc, char const *argv[]) {
  if(argc < 2) {
    cout << "ERREUR FATALE DE LA MORT QUI TUE: pas d'argument" << endl;
    return 255;
  }
  char *p;
  int disques;

  long conv = strtol(argv[1], &p, 10);

  if (*p != '\0' || conv > INT_MAX) {
    cout << "ERREUR PAS TROP FATALE MAIS QUAND MEME: pas un nombre" << endl;
    return 255;
  }
  disques = conv;

  Turn turns(disques);
  PilesManager manager(disques, &turns);

  Pile* target = manager[2];
  Pile* from = manager[0];
  Disque *first = manager[0]->topDisque();
  int turn;
  bool goingto2 = false;
  Pile* dest;
  bool last = false;
  do {
    manager.describe();
    turn = turns.turn();
    if(turn+1 == disques) {
      if(last) break;
      last = true;
      if(!manager.moveDisque(manager[0], manager[2])) exit(-1);
      from = manager[1];
      if(turns.turn()+1 == disques) break;
    }
    else if(turn == 0) {
      if(goingto2) {
        dest = manager.disque(1)->parent();
        goingto2 = false;
      }
      else {
        if(!first->parent()->even() && first->parent() != target) dest = target;
        else if(
          (!first->parent()->even() && first->parent() == target && (first->parent()->index() + 1) % PILES != from->index()) ||
          (first->parent()->even() && (first->parent()->index() + 1) % PILES != target->index()))
          dest = manager[(first->parent()->index() + 1) % PILES];
        else dest = manager[(first->parent()->index() + 2) % PILES];
        goingto2 = true;
      }
      manager.moveDisque(first->parent(), dest);
    }
    else {
      if(!manager.moveDisque(manager.disque(turn)->parent(), manager[(manager.disque(turn)->parent()->index()+1)%PILES]))
        manager.moveDisque(manager.disque(turn)->parent(), manager[(manager.disque(turn)->parent()->index()+2)%PILES]);
    }
    cout << endl;
  } while(1);
  cout << endl;
  manager.describe();

  return manager.moves();
}

/*
Regle step 1?
  Va vers plus grand hors de from
  Si deja va vers plus petit
*/

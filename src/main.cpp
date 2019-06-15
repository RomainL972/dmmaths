#include <iostream>
#include <string>
#include <limits.h>  // for INT_MAX
#include "logger.h"
#include "dmmaths.h"

using namespace std;

int main(int argc, char const *argv[]) {
  bool logMoves = false;
  if(argc >= 3) logMoves = true;
  Logger logger(Logger::Stdout);
  if(logMoves)
    logger.setMovesLogType(Logger::File);
  if(argc < 2)
    logger.error("No argument", true);
  char *p;
  int disques;

  long conv = strtol(argv[1], &p, 10);

  if (*p != '\0' || conv > INT_MAX)
    logger.error("Argument isn't a good number", true);
  disques = conv;

  DMMaths dmmaths;
  dmmaths.setLogger(&logger);
  dmmaths.setDisques(disques);
  dmmaths.execute();

  logger.success(dmmaths.getCounter());
  return EXIT_SUCCESS;
}

#ifndef LEBBADI_LOGGER_H
#define LEBBADI_LOGGER_H

#include <string>
#include <fstream>
#include <thread>
#include <vector>

class PilesManager;

class Logger {
  public:
    Logger(bool logMoves);
    ~Logger();
    void error(std::string message, bool fatal=true);
    void logMove(int from, int to);
    void success(int moves);
  private:
    std::ofstream m_logFile;
    std::ofstream m_movesFile;
    bool m_logMoves;
};

/*
Log file format:
comma separated values

*/

#endif

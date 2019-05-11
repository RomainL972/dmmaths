#ifndef LEBBADI_LOGGER_H
#define LEBBADI_LOGGER_H

#include <string>
#include <fstream>

class PilesManager;

class Logger {
  public:
    Logger(std::string filename);
    ~Logger();
    void error(std::string message, bool fatal=true);
    void logState(std::string message="");
    void setPilesManager(PilesManager *manager);
    void success(int moves);
  private:
    PilesManager *m_manager;
    std::ofstream m_logFile;
};

/*
Log file format:
comma separated values

*/

#endif

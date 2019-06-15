#ifndef LEBBADI_LOGGER_H
#define LEBBADI_LOGGER_H

#include <string>
#include <fstream>
#include <thread>
#include <vector>

class PilesManager;

class Logger {
  public:
    enum LogType {
      File,
      Stdout,
      None
    };
    Logger(LogType messagesLogType=None, LogType movesLogType=None, std::string messagesFileName="log.txt", std::string movesFileName="moves.txt");
    ~Logger();
    void error(std::string message, bool fatal=true);
    void logMove(int from, int to);
    void success(unsigned long long moves);
    void setMessagesLogType(LogType type, std::string messagesFileName="log.txt");
    LogType getMessagesLogType() const;
    void setMovesLogType(LogType type, std::string movesFileName="moves.txt");
    LogType getMovesLogType() const;
  private:
    LogType m_messagesLogType;
    std::ofstream m_messagesLogFile;
    LogType m_movesLogType;
    std::ofstream m_movesLogFile;
};

#endif

#include "logger.h"
#include "piles_manager.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Logger::Logger(LogType messagesLogType, LogType movesLogType,
  string messagesFileName, string movesFileName):
  m_messagesLogType(messagesLogType), m_movesLogType(movesLogType)
{
  if(messagesLogType == File && !messagesFileName.empty()) {
    m_messagesLogFile.open(messagesFileName);
    if(m_messagesLogFile.fail()) m_messagesLogType = Stdout;
  }
  if(movesLogType == File && !movesFileName.empty()) {
    m_movesLogFile.open(movesFileName);
    if(m_movesLogFile.fail()) m_movesLogType = Stdout;
  }
}

Logger::~Logger() {
  if(m_messagesLogFile.is_open())
    m_messagesLogFile.close();
  if(m_movesLogFile.is_open())
    m_movesLogFile.close();
}

void Logger::error(std::string message, bool fatal) {
  if(fatal)
    message = string("[FATAL ERROR] ").append(message);
  else
    message = string("[ERROR]").append(message);
  switch(m_messagesLogType) {
    case File:
      m_messagesLogFile << message << endl;
      if(m_messagesLogFile.good())
        break;
    case Stdout:
      cout << message << endl;
      break;
    default:
      break;
  }
  if(fatal)
    exit(EXIT_FAILURE);
}

void Logger::logMove(int from, int to) {
  switch(m_movesLogType) {
    case File:
      m_movesLogFile << from << ',' << to << endl;
      if(m_movesLogFile.good())
        break;
    case Stdout:
      cout << from << ',' << to << endl;
      break;
    default:
      break;
  }
}

void Logger::success(unsigned long long moves) {
  switch(m_messagesLogType) {
    case File:
      m_messagesLogFile << "Finished in " << moves << " moves" << endl;
      if(m_messagesLogFile.good())
        break;
    case Stdout:
      cout << "Finished in " << moves << " moves" << endl;
      break;
    default:
      break;
  }
}

void Logger::setMessagesLogType(LogType type, string fileName) {
  if(type == File) {
    if(fileName.empty())
      return;
    m_messagesLogFile.open(fileName);
    if(m_messagesLogFile.fail())
      return;
  }
  m_messagesLogType = type;
}

Logger::LogType Logger::getMessagesLogType() const {
  return m_messagesLogType;
}

void Logger::setMovesLogType(LogType type, string fileName) {
  if(type == File) {
    if(fileName.empty())
      return;
    m_movesLogFile.open(fileName);
    if(m_movesLogFile.fail())
      return;
  }
  m_movesLogType = type;
}

Logger::LogType Logger::getMovesLogType() const {
  return m_movesLogType;
}

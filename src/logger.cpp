#include "logger.h"
#include "piles_manager.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Logger::Logger(bool logMoves) : m_logMoves(logMoves){
  m_logFile.open("log.txt", ios::trunc);
  if(!m_logFile.is_open()) error("Couldn't open log file", false);
  if(logMoves) {
    m_movesFile.open("moves.txt", ios::trunc);
    if(!m_movesFile.is_open()) error("Couldn't open moves file", false);
  }
}

Logger::~Logger() {
  m_logFile.close();
  m_movesFile.close();
}

void Logger::error(std::string message, bool fatal) {
  if(fatal){
    cout << "[FATAL ERROR] " << message << endl;
    exit(EXIT_FAILURE);
  }
  else cout << "[ERROR]" << message << endl;
}

void Logger::logMove(int from, int to) {
  if(!m_logMoves || !m_movesFile.is_open()) return;
  m_movesFile << from << ',' << to << endl;
}

void Logger::success(int moves) {
  if(!m_logFile.is_open()) return;
  m_logFile << moves;
}

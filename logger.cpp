#include "logger.h"
#include "piles_manager.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Logger::Logger(string filename){
  m_logFile.open(filename, ios::trunc);
  m_movesFile.open("moves.txt", ios::trunc);
  if(!m_logFile.is_open()) error("Couldn't open log file", false);
  //m_logFile << "message,turn,moves" << endl;
}

Logger::~Logger() {
  m_logFile.close();
}

void Logger::error(std::string message, bool fatal) {
  logState(message);
  if(fatal){
    cout << "[FATAL ERROR] " << message << endl;
    exit(EXIT_FAILURE);
  }
  else cout << "[ERROR]" << message << endl;
}

void Logger::logState(string message) {
  return;
  if(m_manager == nullptr || !m_logFile.is_open()) return;
  m_logFile << '"' << message << "\"," << m_manager->currentTurn() <<
  ',' << m_manager->moves() << endl;
}

void Logger::logMove(int from, int to) {
  if(!m_movesFile.is_open()) {
    error("Moves file not open", false);
    return;
  }
  m_movesFile << from << ',' << to << endl;
}

void Logger::setPilesManager(PilesManager *manager) {
  m_manager = manager;
}

void Logger::success(int moves) {
  m_logFile << moves;
}

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;
enum LOG_LEVEL {
  INFO = 0,
  WARNING = 1,
  ERROR = 2,
  FATAL = 3,
};

const std::unordered_map<LOG_LEVEL, string> log_level_string = {
    {INFO, "INFO"},
    {WARNING, "WARNING"},
    {ERROR, "ERROR"},
    {FATAL, "FATAL"},
};

class log {
public:
  log() { uncaught = std::uncaught_exceptions(); }

  ~log() {
    if (uncaught >= std::uncaught_exceptions()) {
      std::cout << log_level_string.at(this->level) << " " << stream.str()
                << std::endl;
    }
  }

  std::stringstream stream;
  int uncaught;
  static LOG_LEVEL level;

  void setLogLevel(LOG_LEVEL level) { log::level = level; }
};

LOG_LEVEL log::level = INFO;

template <typename T> log &operator<<(log &record, T &&t) {
  record.stream << std::forward<T>(t);
  return record;
}

template <typename T> log &operator<<(log &&record, T &&t) {
  return record << std::forward<T>(t);
}

log &operator<<(log &&record, LOG_LEVEL &&level) {
  record.setLogLevel(level);
  return record;
}
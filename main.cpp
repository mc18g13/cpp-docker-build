#include <iostream>
#include <sstream>
#include <string>

using namespace std;
enum LOG_LEVEL {
  INFO = 0,
  WARNING = 1,
  ERROR = 2,
  FATAL = 3,
};

class log {
public:

  log() { uncaught = std::uncaught_exceptions(); }

  ~log() {
    if (uncaught >= std::uncaught_exceptions()) {
      std::cout << this->level << " " << stream.str() << std::endl;
    }
  }

  std::stringstream stream;
  int uncaught;
  static LOG_LEVEL level;

  void setLogLevel(LOG_LEVEL level) {
    log::level = level;
  }
};

template <typename T> log &operator<<(log &record, T &&t) {
  record.stream << std::forward<T>(t);
  return record;
}

template <typename T> log &operator<<(log &&record, T &&t) {
  return record << std::forward<T>(t);
}

void operator<<(log &&record, LOG_LEVEL &&level) {
  record.setLogLevel(level);
}

int main() { 
  log() << FATAL;
  log() << "Hello world! " << 42;
}
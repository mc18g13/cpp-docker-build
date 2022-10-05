#include "logger.h"

int main() {
  log() << FATAL << "Hello world! " << 42;
  log() << INFO << "Hello world! " << 42;
}
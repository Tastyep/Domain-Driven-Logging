#ifndef DISPATCHER_LOGGER_H
#define DISPATCHER_LOGGER_H

#include <iostream>
#include <string>

class Logger {
public:
  void info(const std::string &msg) {
    std::cout << "[INFO]: " << msg << std::endl;
  }
};

#endif

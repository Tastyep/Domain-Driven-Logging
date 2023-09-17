#ifndef DISPATCHER_USER_CREATED_H
#define DISPATCHER_USER_CREATED_H

#include <string>
#include <utility>

#include "event.h"

class UserCreated : public Event {
public:
  UserCreated(std::size_t id, std::size_t modelId, std::string name)
      : Event(id, modelId), name(std::move(name)) {}

  std::string name;
};
BOOST_DESCRIBE_STRUCT(UserCreated, (Event), (name));

#endif

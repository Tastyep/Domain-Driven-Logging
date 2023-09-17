#ifndef DISPATCHER_EVENT_H
#define DISPATCHER_EVENT_H

#include <cstddef>

#include <boost/describe.hpp>

class Event {
public:
  Event(std::size_t id, std::size_t modelId) : id(id), modelId(modelId) {}
  virtual ~Event() = 0;

  std::size_t id;
  std::size_t modelId;
};
BOOST_DESCRIBE_STRUCT(Event, (), (id, modelId));

#endif

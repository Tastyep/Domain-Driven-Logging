#ifndef DISPATCHER_DISPTCHER_H
#define DISPATCHER_DISPTCHER_H

#include <concepts>
#include <cstddef>
#include <format>
#include <functional>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>

#include "event.h"
#include "logger.h"
#include "stringify.h"

class Dispatcher {
public:
  explicit Dispatcher(std::shared_ptr<Logger> logger)
      : _logger(std::move(logger)) {}

  template <std::derived_from<Event> EventType>
  void observe(std::function<void(const EventType &)> handle) {
    const auto &id = typeid(EventType);
    _eventIdToHandles[id.hash_code()].push_back(
        [func = std::move(handle)](const Event &event) {
          const auto &derivedEvent = dynamic_cast<const EventType &>(event);
          func(derivedEvent);
        });
  }

  template <std::derived_from<Event> EventType>
  void dispatch(const EventType &event) {
    const auto &id = typeid(EventType);
    const auto &handles = _eventIdToHandles[id.hash_code()];

    const auto eventStr = stringify(event);
    _logger->info(std::format("Dispatching {}", eventStr));

    for (const auto &handle : handles) {
      handle(event);
    }
  }

private:
  std::shared_ptr<Logger> _logger;

  std::unordered_map<std::size_t,
                     std::vector<std::function<void(const Event &)>>>
      _eventIdToHandles;
};

#endif

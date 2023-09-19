# Domain-Driven-Logging

Domain-Driven-Logging is a project that demonstrates how to implement systematic logging in a Domain-Driven Design (DDD) approach. It showcases the use of events, dispatchers, and observers to handle and log domain-specific events.

## Overview

1. **Event**: Represents a domain-specific event. In this example, we have a `UserCreated` event which is triggered when a user is created.

2. **Dispatcher**: Responsible for managing and dispatching events. It allows observers to register and listen for specific events. When an event is dispatched, it logs the event and notifies all registered observers.

3. **Logger**: A simple logging utility that logs messages to the console.

4. **Stringify**: A utility to convert events into a string representation, making it easier to log them.

## How It Works

1. An instance of `Logger` is created.
2. An instance of `Dispatcher` is created and is provided with the `Logger`.
3. An observer is registered to the `Dispatcher` to listen for `UserCreated` events. When such an event is received, it logs a message.
4. Two `UserCreated` events are dispatched. For each event, the dispatcher logs the event details and notifies the registered observer.

## Code Snippet

Here's a brief snippet from the `main.cpp` that demonstrates the flow:

```cpp
int main() {
  auto logger = std::make_shared<Logger>();
  Dispatcher dispatcher(logger);

  dispatcher.observe<UserCreated>(
      [&logger](const UserCreated &) { logger->info("Received UserCreated"); });

  dispatcher.dispatch(UserCreated{0, 0, "John"});
  dispatcher.dispatch(UserCreated{1, 1, "Mike"});
}
```

When the above code is executed, the following logs are produced:

```bash
[INFO]: Dispatching UserCreated{ Event{ .id = 0, .modelId = 0}, .name = John}
[INFO]: Received UserCreated
[INFO]: Dispatching UserCreated{ Event{ .id = 1, .modelId = 1}, .name = Mike}
[INFO]: Received UserCreated
```

## Conclusion

Domain-Driven-Logging provides a structured way to handle and log domain-specific events using the principles of DDD. It's a great starting point for anyone looking to integrate systematic logging into their DDD projects.


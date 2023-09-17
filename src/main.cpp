#include "dispatcher.h"
#include "user_event.h"

int main() {
  auto logger = std::make_shared<Logger>();
  Dispatcher dispatcher(logger);

  dispatcher.observe<UserCreated>(
      [&logger](const UserCreated &) { logger->info("Received UserCreated"); });

  dispatcher.dispatch(UserCreated{0, 0, "John"});
  dispatcher.dispatch(UserCreated{1, 1, "Mike"});
}

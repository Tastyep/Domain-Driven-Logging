#ifndef DISPATCHER_STRINGIFY_H
#define DISPATCHER_STRINGIFY_H

#include <ostream>
#include <sstream>
#include <string>
#include <utility>

#include <boost/core/demangle.hpp>
#include <boost/describe.hpp>
#include <boost/mp11.hpp>

template <
    class T,
    class Bd =
        boost::describe::describe_bases<T, boost::describe::mod_any_access>,
    class Md =
        boost::describe::describe_members<T, boost::describe::mod_any_access>>
std::ostream &operator<<(std::ostream &os, T const &data) {
  const char *mangledName = typeid(T).name();
  const auto demangledName = boost::core::demangle(mangledName);

  os << demangledName << "{ ";

  bool first = true;
  boost::mp11::mp_for_each<Bd>([&](auto desc) {
    if (!first) {
      os << ", ";
    }
    first = false;

    using Base = typename decltype(desc)::type;
    os << (Base const &)data;
  });

  boost::mp11::mp_for_each<Md>([&](auto desc) {
    if (!first) {
      os << ", ";
    }
    first = false;

    os << "." << desc.name << " = " << data.*desc.pointer;
  });

  os << "}";
  return os;
}

template <typename T> //
std::string stringify(const T &data) {
  std::stringstream ss;

  ss << data;

  return ss.str();
}

#endif

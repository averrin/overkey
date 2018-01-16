#pragma once
#include <string>
#include "scancodes.hpp"

namespace hotkeys {
struct Stroke {
  Keys code;
  std::string name;
  State state;
};
}
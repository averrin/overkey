#pragma once
#include <vector>
#include "stroke.hpp"

namespace hotkeys {
  struct Sequence {
    std::vector<hotkeys::Stroke> keys;
    std::string desc;
  };
}

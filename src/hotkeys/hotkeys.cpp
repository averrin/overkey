#include "hotkeys.h"
#include "stroke.hpp"
#include "scancodes.hpp"
#include "sequence.hpp"
#include <string>
#include <iterator>

std::string hotkeys::GetKeyName(hotkeys::Keys key)
{
    return keynames[key];
}

hotkeys::Sequence hotkeys::Process(hotkeys::Keys key, hotkeys::State state)
{
  const auto stroke = hotkeys::Stroke{key, GetKeyName(key), state};
  const auto seq = hotkeys::Sequence{{stroke}};
  return seq;
}

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

void hotkeys::KeyManager::AddSequence(const hotkeys::Sequence seq) {
  sequences.push_back(seq);
}

hotkeys::Sequence hotkeys::KeyManager::Process(const hotkeys::Keys key, const hotkeys::State state)
{
  const auto stroke = hotkeys::Stroke{key, GetKeyName(key), state};
  const auto seq = hotkeys::Sequence{{stroke}, "pressed seq"};
  return seq;
}

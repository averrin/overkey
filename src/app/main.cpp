#include "format.h"
#include "hotkeys/hotkeys.h"
#include <iostream>
#include <memory>

int main() {
  auto const manager = std::make_unique<hotkeys::KeyManager>();
  auto const testSeq = hotkeys::Sequence{{hotkeys::Stroke{hotkeys::Keys::SC_E},
                                          hotkeys::Stroke{hotkeys::Keys::SC_D}},
                                         "Test Seq"};
  auto const pressedSeq =
      manager->Process(hotkeys::Keys::SC_E, hotkeys::State::DOWN);
  fmt::print(pressedSeq.desc);
  return 0;
}

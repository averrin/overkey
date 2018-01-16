#include <iostream>
#include "hotkeys/hotkeys.h"
#include "format.h"

int main()
{
    fmt::print(hotkeys::GetKeyName(hotkeys::Keys::SC_E));
    return 0;
}

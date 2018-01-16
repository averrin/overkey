
#pragma once

// Define preprocessor definitions needed for building DLLs on Windows
#ifdef WIN32 && defined(BUILD_SHARED_LIBS)

    #ifdef hotkeys_EXPORTS // Are we creating the DLL?
        #define API __declspec(dllexport)
    #else //  We're importing the DLL
        #define API __declspec(dllimport)
    #endif

#else // not WIN32 or not BUILD_SHARED_LIBS
    #define API
#endif

// Standard library dependencies
#include <string>

// Platform-specific includes go here
#ifdef __linux__
// Linux includes

#elif defined(_WIN32)
// Windows includes

#elif defined(__APPLE__)
// Mac includes

#endif // __linux__

namespace hotkeys
{
    API std::string HelloWorld();
}

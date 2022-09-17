#pragma once

#ifdef _WIN32
    #ifdef _WIN64
        #define ZR_PLATFORM_WINDOWS
    #else
        #error "x86 is not supported"
    #endif
#elif defined(__linux__)
    #define ZR_PLATFORM_LINUX
    //#error "Linux is not supported"
#elif defined(__APPLE__) || defined(__MACH__)
    #error "MacOS is not supported"
#else
    #error "Unknown Operating System"
#endif


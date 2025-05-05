#pragma once

#include <iostream>

// compilers treat empty __VA_ARGS__ differently, c++20 __VA_OPT__ solves it
// _9, _8, _7, _6, _5, _4, _3, _2, _1, N, ...) N
// _x, xx, 07, 06, 05, 04, 03, 02, 01, 0
#define ASSERT_ARGC_X(_9, _8, _7, _6, _5, _4, _3, _2, _1, N, ...) N
#define ASSERT_ARGC(...) ASSERT_ARGC_X(_x, __VA_OPT__(,) __VA_ARGS__, 07, 06, 5, 4, 3, 2, 1, 0)
#define MAX_ARGC        2

#define ASSERT_ARGV(argc, ...) \
    do { \
        static_assert(argc < MAX_ARGC, "too many args"); \
        if (argc > 0) { \
            std::cerr << "\x1b[34mMessage:\x1b[0m" << std::endl \
                      << #__VA_ARGS__ << std::endl; \
        } \
    } while (0)

#define ASSERT(COND, ...) \
    do { \
        if (!(COND)) { \
            std::cerr << "\x1b[31mAssertion failed at: " \
                << __FILE__ << ":" <<__LINE__ << ": \x1b[0m" \
                << std::endl << #COND << std::endl; \
            ASSERT_ARGV(ASSERT_ARGC(__VA_ARGS__), __VA_ARGS__); \
            std::exit(1); \
        } \
    } while (0)
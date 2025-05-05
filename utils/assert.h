#pragma once

#include <iostream>

#define ASSERT_ARGC_X(a, b, c, d, e, f, g, h, i, N, ...) N

// on macOS Clang when use ASSERT(1 == 1) (with no extra arguments),
// the variadic arguments expansion is causing unexpected behavior.
#define ASSERT_ARGC(...) \
    ASSERT_ARGC_X(dummy, ## __VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0)
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
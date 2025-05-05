#pragma once

#include <filesystem>
#include <mutex>
#include <variant>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <type_traits>

#ifndef __XMAKE__
#define __XMAKE__ "XMAKE is not defined"
#endif
constexpr static auto XMAKE = __XMAKE__;

int cmd_run(const std::string& cmd, const std::string& proj, const std::string& log);

template<typename T>
static inline bool test_exercise(const T& id, const std::string& log) {
    std::ofstream file;
    std::stringstream ss;

    if (!log.empty()) {
        file.open(log, std::ios::out | std::ios::app);
    }
    std::ostream &os =(!log.empty()) ? file : std::cout;

    ss << "exercise" << id;
    const auto str = ss.str();

    os << "\x1b[34m" << str << " testing" << "\x1b[0m" << std::endl
       << "==================" << std::endl;
    auto pass = cmd_run("", str, log) == EXIT_SUCCESS && cmd_run("run", str, log) == EXIT_SUCCESS;
    os << "=================" << std::endl
       << "\x1b[" << (pass ? 32 : 31) << 'm' << str << (pass ? " passed" : " failed") << "\x1b[0m" << std::endl
       << std::endl;

    return pass;
}

struct Console {};
struct Null {};

struct Log {
    std::variant<Console, Null, std::filesystem::path> dst;
    std::vector<bool> result;
    std::mutex mutex;

    template<typename T>
    Log &operator<<(const T& id);
};

template<typename T>
Log &Log::operator<<(const T& n) {
    namespace fs = std::filesystem;
    bool pass = false;

    if (std::holds_alternative<Console>(this->dst)) {
        pass = test_exercise(n, {});
    } else if (std::holds_alternative<Null>(this->dst)) {
#if defined(_WIN32)
        const std::string null = "nul";
#elif defined(__linux__) || defined(__unix__) || defined(__MACOSX__) || defined(__APPLE__)
        const std::string null = "/dev/null";
#else
#error "Unsupported platform"
#endif
        pass = test_exercise(n, null);
    } else {
        const auto path = fs::absolute(fs::path(XMAKE) / "log" / std::get<fs::path>(this->dst));
        pass = test_exercise(n, path.string());
    }

    {
        std::lock_guard lock(this->mutex);
        this->result.push_back(pass);
    }

    return *this;
}
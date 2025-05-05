#include "test.h"

namespace fs = std::filesystem;

int process_run(const std::string& cmd, const std::string& proj, const std::string& log) {
    static const auto exercises = fs::absolute(fs::path(XMAKE) / "exercises");
    auto command = std::string("xmake ") + cmd + " -P \"" + exercises.string() + "\" " + proj;
    if (!log.empty()) {
        command += " >> ";
        command += log;
        command += " 2>&1";
    }
    return std::system(command.c_str());
}

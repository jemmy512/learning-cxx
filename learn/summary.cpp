#include "test.h"
#include <atomic>
#include <thread>
#include <queue>
#include <algorithm>

namespace fs = std::filesystem;

using ExerciceCallback = std::function<void(const std::string& file)>;

void for_exercises(const ExerciceCallback& cb) {
    const auto exercises = fs::absolute(fs::path(XMAKE) / "exercises");

    for (const auto& entry : fs::directory_iterator(exercises)) {
        if (entry.is_directory()) {
            cb(entry.path().filename().string());
        }
    }
}

int main(int argc, char **argv) {
    if (argc == 2) {
        Log log{Console{}};

        for_exercises([&log](const auto& str) {
            log << str;
        });

        return EXIT_SUCCESS;
    }

    if (argc == 1) {
        auto concurrency = std::max<int>(1, std::thread::hardware_concurrency());

        std::mutex queueMutex;
        std::queue<std::string> taskQueue;
        std::atomic_int nrFileDone{0};
        std::vector<std::thread> threads;
        threads.reserve(concurrency);

        for_exercises([&taskQueue](const auto& str) {
            taskQueue.emplace(str);
        });

        std::cout << "concurrency: " << concurrency << std::endl;
        Log log{Null{}};

        auto worker = [&log, &taskQueue, &queueMutex, &nrFileDone, files_total = taskQueue.size()](int tid) {
            while(true) {
                std::string file;
                {
                    std::lock_guard<std::mutex> guard(queueMutex);
                    if (taskQueue.empty()) {
                        break;
                    }
                    file = std::move(taskQueue.front());
                    taskQueue.pop();
                }

                std::printf("----------------\nTID[%d] processing: %s\n", tid, file.c_str());

                log << file;

                int done = nrFileDone.fetch_add(1) + 1;
                std::printf("Progress: %d/%zu (%.1f%%)\n----------------\n\n",
                    done, files_total,
                    (100.0 * done) / files_total);
            }
        };

        for (unsigned int i = 0; i < concurrency; ++i) {
            threads.emplace_back(worker, i);
        }

        for (auto& thd : threads) {
            thd.join();
        }

        return EXIT_SUCCESS;
    }
    std::cerr << "Usage: xmake run summary [--simple]" << std::endl;

    return EXIT_FAILURE;
}

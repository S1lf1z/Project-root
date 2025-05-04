#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>
#include <chrono>
#include "cleanup.h"

namespace fs = std::filesystem;

void clean_up(const std::string& target) {
    std::remove("Self$.cpp");

    std::ofstream content_file("content.txt");
    content_file << "Nothing for here...\n";
    content_file.close();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    fs::remove("content.txt");

    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.path().extension() == target) {
            fs::remove(entry.path());
        }
    }

    std::cout << "Finished\n";
}

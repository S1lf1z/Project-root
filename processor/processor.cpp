#include <filesystem>
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "processor.h"

namespace fs = std::filesystem;

void process_files(const std::string& target) {
    for (const auto& entry : fs::recursive_directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::string old_file_path = entry.path().string();
            std::string new_file_path = "./" + entry.path().filename().string();
            fs::rename(old_file_path, new_file_path);
        }
    }

    std::vector<std::string> programs;
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.path().extension() == target) {
            programs.push_back(entry.path().string());
        }
    }

    std::ofstream content_file("content.txt", std::ios::app);
    for (const auto& p : programs) {
        std::ifstream program_file(p);
        std::string line;
        content_file << p << "\n";
        while (std::getline(program_file, line)) {
            content_file << line << "\n";
        }
        content_file << "\n";
    }

    content_file.close();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Self$ infected all the " << target << " files.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

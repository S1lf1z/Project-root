#include <iostream>
#include <thread>
#include <chrono>
#include "banner.h"

void print_banner() {
    std::cout << "Project-Root\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "project-root-\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "\n";

    const std::string ascii_art[] = {
        "███████████████████████████",
        "███████▀▀▀░░░░░░░▀▀▀███████",
        "████▀░░░░░░░░░░░░░░░░░▀████",
        "███│░░░░░░░░░░░░░░░░░░░│███",
        "██▌│░░░░░░░░░░░░░░░░░░░│▐██",
        "██░└┐░░░░░░░░░░░░░░░░░┌┘░██",
        "██░░└┐░░░░░░░░░░░░░░┌┘░░██",
        "██░░┌┘▄▄▄▄▄░░░░░▄▄▄▄▄└┐░░██",
        "██▌░│█▌▌░S1lf1▐GitHub█ │░▐█",
        "███░│▐███▀▀░░▄░░▀▀███▌│░███",
        "██▀─┘░░░░░░░░░░░░░░░░░└─▀██",
        "██▄░░░▄▄▄▓░░▀█▀░░▓▄▄▄░░░▄██",
        "████▄─┘██▌░░░░░░░▐██└─▄████",
        "█████░░▐█─┬┬┬┬┬┬┬─█▌░░█████",
        "████▌░░░▀┬┼┼┼┼┼┼┼┬▀░░░▐████",
        "█████▄░░░└┴┴┴┴┴┴┴┘░░░▄█████",
        "███████▄░░░░░░░░░░░▄███████",
        "██████████▄▄▄▄▄▄▄██████████",
        "███████████████████████████"
    };

    for (const auto& line : ascii_art) {
        std::cout << line << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    std::cout << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

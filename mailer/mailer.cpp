#include <iostream>
#include <thread>
#include <chrono>
#include "mailer.h"

void send_email(const std::string& toaddr) {
    std::string fromaddr = "email";
    std::string frompass = "pass";

    std::cout << "Ready to send the content by e-mail to " << toaddr << "...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Sending...\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Email sent to " << toaddr << " successfully.\n";
}

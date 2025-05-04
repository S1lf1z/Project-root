#include <getopt.h>
#include <string>
#include "banner/banner.h"
#include "processor/processor.h"
#include "mailer/mailer.h"
#include "cleanup/cleanup.h"

int main(int argc, char* argv[]) {
    std::string target;
    std::string mail;

    struct option long_options[] = {
        {"target", required_argument, nullptr, 't'},
        {"mail", required_argument, nullptr, 'm'},
        {nullptr, 0, nullptr, 0}
    };

    int option_index = 0;
    int c;
    while ((c = getopt_long(argc, argv, "t:m:", long_options, &option_index)) != -1) {
        switch (c) {
        case 't':
            target = optarg;
            break;
        case 'm':
            mail = optarg;
            break;
        default:
            break;
        }
    }

    print_banner();
    process_files(target);
    send_email(mail);
    clean_up(target);

    return 0;
}
// Create by https://github.com/S1lf1z
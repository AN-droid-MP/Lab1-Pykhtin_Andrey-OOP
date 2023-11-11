#include <iostream>
#include <string>
#include <limits>
#include "Input.h"

void signalHandler(int signal) {
    std::cout << "CTRL + C detected. ";
}

int getInteger(std::istream &in) {
    int num;

    while (true) {

        std::cout << "Enter an integer value: ";

        signal(SIGINT, signalHandler);

        try {

            in >> num;

            if (in.fail()) {
                if (in.eof()) {
                    std::cout << "EOF detected.";
                    exit(0);
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::runtime_error("Invalid input format. \n");
            }

            break;
        }
        catch (const std::exception &exception) {
            std::cerr << exception.what();
        }
    }

    return num;
}



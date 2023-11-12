#include <iostream>
#include <string>
#include <limits>
#include "../exception/type_mismatch_error.cpp"
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
                    throw std::runtime_error("EOF detected. Program will be completed\n");
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw type_mismatch_error("Invalid input format. \n");
            }

            break;
        }
        catch (const type_mismatch_error &exception) {
            std::cerr << exception.what();
        }
    }

    return num;
}



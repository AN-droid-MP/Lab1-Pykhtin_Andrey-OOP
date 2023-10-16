#include <iostream>
#include <string>
#include "../Matrix/Matrix.h"
#include "../IOHelper/IOHelper.h"
#include "../MatrixProcessing/MatrixProcessing.h"

int getIntegerInput() {
    std::string input;
    int num;
    while (true) {
        input = getInput();
        try {
            num = std::stoi(input);
            break;
        } catch (const std::invalid_argument &e) {
            std::cerr << "Invalid argument: " << e.what() << std::endl;
        } catch (const std::out_of_range &e) {
            std::cerr << "Out of range: " << e.what() << std::endl;
        }
    }
    return num;
}

std::string getInput() {
    std::string input;
    while (true) {
        std::cin >> input;
        trim(input);
        if (!isBlank(input)) {
            return input;
        } else {
            std::cout << "Input can't be blank" << std::endl;
        }
    }
}

bool isBlank(const std::string &str) {
    size_t firstNonSpace = str.find_first_not_of(' ');
    size_t lastNonSpace = str.find_last_not_of(' ');
    return !(firstNonSpace != std::string::npos && lastNonSpace != std::string::npos);
}

void trim(std::string &str) {
    size_t firstNonSpace = str.find_first_not_of(' ');
    size_t lastNonSpace = str.find_last_not_of(' ');
    if (firstNonSpace != std::string::npos && lastNonSpace != std::string::npos) {
        str = str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
    }
}

void matrixOutput(Matrix matrix) {
    for (int i = 0; i < matrix.size; ++i) {
        for (int j = 0; j < matrix.size; ++j) {
            std::cout << matrix.data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void checkMatrixAndPrintResults(const Matrix &matrix) {
    Matrix result = processMatrix(matrix, false);

    if (result.data[0][0] == 0) {
        std::cout << "Elements not found in matrix." << std::endl;
    } else {
        std::cout << "Not found elements in rows: ";
        for (int i = 0; i < matrix.size; ++i) {
            if (result.data[i][0] == 0) {
                std::cout << i + 1;
                if (i < matrix.size - 1) {
                    std::cout << ", ";
                }
            }
        }
        std::cout << std::endl;
    }
}
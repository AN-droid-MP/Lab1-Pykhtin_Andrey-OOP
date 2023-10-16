#include <iostream>
#include "Matrix.h"
#include "../IOHelper/IOHelper.h"

Matrix initialize(int size) {
    Matrix matrix{};
    matrix.size = size;

    matrix.data = new int *[size];
    for (int i = 0; i < size; ++i) {
        matrix.data[i] = new int[size];
    }

    return matrix;
}

[[maybe_unused]] void fillMatrix(Matrix &matrix) {
    for (int i = 0; i < matrix.size; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << "Enter matrix element [" << i << "][" << j << "] ";
            matrix.data[i][j] = getIntegerInput();
            matrix.data[j][i] = matrix.data[i][j];
        }
    }
}

[[maybe_unused]] void freeMatrix(Matrix &matrix) {
    for (int i = 0; i < matrix.size; ++i) {
        delete[] matrix.data[i];
    }
    delete[] matrix.data;
}
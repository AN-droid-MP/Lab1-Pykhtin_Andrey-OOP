#include "Matrix.h"
#include "../Input/Input.h"
#include <iostream>

namespace Matrix {

    Matrix initialize(int size) {
        Matrix matrix;
        matrix.size = size;
        matrix.data.resize(size * (size + 1) / 2);
        return matrix;
    }

    void fillMatrix(Matrix &matrix) {
        for (int i = 0; i < matrix.size; ++i) {
            for (int j = i; j < matrix.size; ++j) {
                std::cout << "Enter matrix element [" << i + 1 << "][" << j + 1 << "] ";
                int value = getInteger(std::cin);
                matrix.data[getIndex(i, j, matrix.size)] = value;
            }
        }
    }

    int getIndex(int row, int col, int size) {
        return row * size - (row - 1) * row / 2 + col - row;
    }


    Matrix createNewMatrix(const Matrix &original) {
        Matrix result = initialize(original.size);
        double avgDigitsInRow;
        int num;

        for (int i = 0; i < original.size; ++i) {

            avgDigitsInRow = averageDigitsInRow(original, i);

            for (int j = 0; j < original.size; ++j) {

                if(i <= j) {
                    num = original.data[getIndex(i, j, original.size)];
                }
                else {
                    num = original.data[getIndex(j, i, original.size)];
                }

                result.data.push_back((avgDigitsInRow < digitsInNumber(num)) ? num : 0);
            }
        }

        return result;
    }

    double averageDigitsInRow(const Matrix &matrix, int row) {
        int sumDigits = 0;
        int num;

        for (int i = 0; i < matrix.size; ++i) {
            if(row <= i) {
                num = matrix.data[getIndex(row, i, matrix.size)];
            }
            else {
                num = matrix.data[getIndex(i, row, matrix.size)];
            }
            sumDigits += digitsInNumber(num);
        }

        return static_cast<double>(sumDigits) / (matrix.size);
    }

    int digitsInNumber(int number) {
        int digits = 0;

        if (number == 0) {
            return 1;
        }

        while (number != 0) {
            number /= 10;
            digits++;
        }

        return digits;
    }

    void originalMatrixOutput(const Matrix &matrix) {
        for (int i = 0; i < matrix.size; ++i) {
            for (int j = 0; j < matrix.size; ++j) {
                if (i <= j) {
                    std::cout << matrix.data[getIndex(i, j, matrix.size)] << " ";
                } else {
                    std::cout << matrix.data[getIndex(j, i, matrix.size)] << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    void resultMatrixOutput(const Matrix &matrix) {
        for (int i = 0; i < matrix.data.size(); ++i) {
            if (matrix.data[i] != 0) {
                std::cout << matrix.data[i] << " ";
            }
        }
    }

    bool isEmpty(const Matrix &matrix) {
        for (int i : matrix.data) {
            if (i != 0) {
                return false;
            }
        }

        return true;
    }
}

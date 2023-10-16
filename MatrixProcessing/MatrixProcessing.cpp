#include "../Matrix/Matrix.h"

double averageDigitsInRow(const Matrix &matrix, int row) {
    int sumDigits = 0;
    for (int j = 0; j < matrix.size; ++j) {
        int num = matrix.data[row][j];
        int digits = 0;
        int tempNum = num;

        while (tempNum != 0) {
            tempNum /= 10;
            digits++;
        }
        sumDigits += digits;
    }
    return static_cast<double>(sumDigits) / matrix.size;
}


[[maybe_unused]] Matrix createNewMatrix(const Matrix &original) {
    Matrix newMatrix = initialize(original.size);

    for (int i = 0; i < original.size; ++i) {
        double avgDigitsInRow = averageDigitsInRow(original, i);

        for (int j = 0; j < original.size; ++j) {
            int num = original.data[i][j];
            int digits = 0;
            int tempNum = num;

            while (tempNum != 0) {
                tempNum /= 10;
                digits++;
            }

            if (digits > avgDigitsInRow) {
                newMatrix.data[i][j] = num;
            }
        }
    }
    return newMatrix;
}


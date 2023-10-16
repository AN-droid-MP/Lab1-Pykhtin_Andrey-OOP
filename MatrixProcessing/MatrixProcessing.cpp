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


Matrix processMatrix(const Matrix &original, bool createNew) {
    Matrix result = initialize(original.size);

    for (int i = 0; i < original.size; ++i) {
        for (int j = 0; j < original.size; ++j) {
            int num = original.data[i][j];
            int digits = 0;
            int tempNum = num;

            while (tempNum != 0) {
                tempNum /= 10;
                digits++;
            }

            if (createNew) {
                double avgDigitsInRow = averageDigitsInRow(original, i);
                if (digits > avgDigitsInRow) {
                    result.data[i][j] = num;
                } else {
                    result.data[i][j] = 0;
                }
            } else {
                if (digits > 0) {
                    return result;
                }
            }
        }
    }

    return result;
}

Matrix createNewMatrix(const Matrix &original) {
    return processMatrix(original, true);
}
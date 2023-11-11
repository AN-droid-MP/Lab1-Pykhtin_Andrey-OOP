
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

namespace Matrix {

    struct Matrix {
        std::vector<int> data;
        int size;
    };

    Matrix initialize(int size);

    int getIndex(int row, int col, int size);

    void fillMatrix(Matrix &matrix);

    Matrix createNewMatrix(const Matrix &original);

    double averageDigitsInRow(const Matrix &matrix, int row);

    int digitsInNumber(int number);

    void originalMatrixOutput(const Matrix& matrix);

    void resultMatrixOutput(const Matrix &matrix);

    bool isEmpty(const Matrix& matrix);
}

#endif //MATRIX_H


#ifndef LAB1_PYKHTIN_ANDREY_2___MATRIX_H
#define LAB1_PYKHTIN_ANDREY_2___MATRIX_H

struct Matrix {
    int **data;
    int size;
};

Matrix initialize(int size);

[[maybe_unused]] void fillMatrix(Matrix &matrix);

[[maybe_unused]] void freeMatrix(Matrix &matrix);

#endif //LAB1_PYKHTIN_ANDREY_2___MATRIX_H

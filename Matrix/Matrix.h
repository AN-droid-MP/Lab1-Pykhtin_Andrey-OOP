
#ifndef LAB1_PYKHTIN_ANDREY_2___MATRIX_H
#define LAB1_PYKHTIN_ANDREY_2___MATRIX_H

struct Matrix {
    int **data;
    int size;
};

Matrix initialize(int size);

void fillMatrix(Matrix &matrix);

void freeMatrix(Matrix &matrix);

#endif //LAB1_PYKHTIN_ANDREY_2___MATRIX_H


#ifndef LAB1_PYKHTIN_ANDREY_2___MATRIXPROCESSING_H
#define LAB1_PYKHTIN_ANDREY_2___MATRIXPROCESSING_H

#include "../Matrix/Matrix.h"

double averageDigitsInRow(const Matrix &matrix, int row);

Matrix createNewMatrix(const Matrix &original);

Matrix processMatrix(const Matrix &original, bool createNew);

#endif //LAB1_PYKHTIN_ANDREY_2___MATRIXPROCESSING_H

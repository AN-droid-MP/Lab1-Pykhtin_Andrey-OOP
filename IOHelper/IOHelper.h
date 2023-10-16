
#ifndef LAB1_PYKHTIN_ANDREY_2___IOHELPER_H
#define LAB1_PYKHTIN_ANDREY_2___IOHELPER_H

#include <string>
#include "../Matrix/Matrix.h"

int getIntegerInput();

std::string getInput();

bool isBlank(const std::string &);

void trim(std::string &);

void matrixOutput(Matrix matrix);

void checkMatrixAndPrintResults(const Matrix &matrix);

#endif //LAB1_PYKHTIN_ANDREY_2___IOHELPER_H

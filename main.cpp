#include <iostream>
#include "IOHelper/IOHelper.h"
#include "MatrixProcessing/MatrixProcessing.h"
#include "Matrix/Matrix.h"


int main() {
    std::cout << "Enter matrix size: ";
    int size = getIntegerInput();
    Matrix matrix = initialize(size);

    fillMatrix(matrix);

    std::cout << "Original Matrix:" << std::endl;
    matrixOutput(matrix);

    Matrix newMatrix = createNewMatrix(matrix);

    std::cout << "New Matrix:" << std::endl;
    matrixOutput(newMatrix);

    freeMatrix(matrix);
    freeMatrix(newMatrix);

    return 0;
}
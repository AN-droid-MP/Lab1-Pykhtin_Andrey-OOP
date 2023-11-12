#include <iostream>
#include "Input/Input.h"
#include "Matrix/Matrix.h"

int main() {
    try {
        std::cout << "Enter matrix size: ";
        int size = 0;
        while (size < 1) {
            size = getInteger(std::cin);
            if (size < 1) {
                std::cout << "Matrix size can't be less than 1" << std::endl;
            }
        }

        Matrix::Matrix matrix = Matrix::initialize(size);

        fillMatrix(matrix);

        std::cout << "Original Matrix:" << std::endl;
        originalMatrixOutput(matrix);

        Matrix::Matrix newMatrix = Matrix::createNewMatrix(matrix);

        std::cout << "New Matrix:" << std::endl;

        if(!isEmpty(newMatrix)){
            resultMatrixOutput(newMatrix);
        }
        else {
            std::cout << "There are no elements in the original matrix that satisfy the condition" << std::endl;
        }
    } catch (std::runtime_error exception) {

    }

    return 0;
}
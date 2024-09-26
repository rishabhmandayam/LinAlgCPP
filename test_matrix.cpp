#include "matrix.h"
#include <iostream>
#include <cassert>

void printMatrix(Matrix& matrix) {
    int cols = matrix.columnCount();

    for (int i = 0; i < matrix.rowCount(); i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix.get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    double dataA[] = {1, 2, 3, 4};
    double dataB[] = {5, 6, 7, 8};

    Matrix A(2, 2, dataA);
    Matrix B(2, 2, dataB);

    std::cout << "Matrix A:" << std::endl;
    printMatrix(A);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(B);

    Matrix C = A + B;

    std::cout << "Matrix C (A + B):" << std::endl;
    printMatrix(C);

    double expectedDataC[] = {6, 8, 10, 12};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            assert(C.get(i, j) == expectedDataC[i * 2 + j]);
        }
    }

    Matrix D = A * B;

    std::cout << "Matrix D (A * B):" << std::endl;
    printMatrix(D);


    double expectedDataD[] = {19, 22, 43, 50};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            assert(D.get(i, j) == expectedDataD[i * 2 + j]);
        }
    }

    double scalar = 10.0;
    Matrix E = A + scalar;

    std::cout << "Matrix E (A + 10):" << std::endl;
    printMatrix(E);


    double expectedDataE[] = {11, 12, 13, 14};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            assert(E.get(i, j) == expectedDataE[i * 2 + j]);
        }
    }

    Matrix F(2, 2, expectedDataC);
    assert(C == F);

    std::cout << "All tests passed!" << std::endl;
    return 0;

}

#include "matrix.h"
#include <stdexcept>

//constructors
Matrix::Matrix(){
    nRows = 1;
    nColumns = 1;
    numberOfElements = 1;
    data = new double[numberOfElements];
    data[0] = 0.0;
}

Matrix::Matrix(int rows, int columns){
    nRows = rows;
    nColumns = columns;
    numberOfElements = nRows * nColumns;
    data = new double[numberOfElements];

    for (int i = 0; i<numberOfElements; i++) {
        data[i] = 0.0;
    }
}

Matrix::Matrix(int rows, int columns, const double* inputData){
    nRows = rows;
    nColumns = columns;
    numberOfElements = nRows * nColumns;
    data = new double[numberOfElements];

    for (int i = 0; i<numberOfElements; i++) {
        data[i] = inputData[i];
    }
}

Matrix::Matrix(const Matrix& copy){
    nRows = copy.nRows;
    nColumns = copy.nColumns;
    numberOfElements = copy.numberOfElements;
    data = new double[numberOfElements];

    for (int i = 0; i<numberOfElements; i++) {
        data[i] = copy.data[i];
    }
}

//Deconstructor
Matrix::~Matrix(){
    if (data != nullptr){
        delete[] data;
    }
}


//functions
bool Matrix::resize(int rows, int columns){
    nRows= rows;
    nColumns = columns;
    numberOfElements = nRows * nColumns;

    delete[] data;
    data = new double[numberOfElements];
    
    if (data != nullptr){
        for (int i = 0; i<numberOfElements; i++) {
            data[i] = 0.0;
        }
        return true;
    }
    else {
        return false;
    }
}

double Matrix::get(int row, int column) {
    int index = index(row, column);
    if (index >= 0) {
        return data[index];
    }
}

int Matrix::rowCount() {
    return nRows;
}

int Matrix::columnCount() {
    return nColumns;
}

//Matrix Operations

//Addition Operations
Matrix operator+ (const Matrix& matrixOne, const Matrix& matrixTwo) {
    int oneRows = matrixOne.nRows;
    int twoRows = matrixTwo.nRows;
    int oneColumns = matrixOne.nColumns;
    int twoColumns = matrixTwo.nColumns;
    
    if (oneRows != twoRows || oneColumns != twoColumns) {
        throw std::invalid_argument("Matrix Dimension Mismatch");
    }

    Matrix result(oneRows, oneColumns);
    for (int i = 0; i < matrixOne.numberOfElements; i++) {
        result.data[i] = matrixOne.data[i] + matrixTwo.data[i];
    }
    return result;
}

Matrix operator+ (const double& scalar, const Matrix& matrix) {
    Matrix result(matrix.nRows, matrix.nColumns);
    for (int i = 0; i < matrix.numberOfElements; i++) {
        result.data[i] = scalar +  matrix.data[i];
    }
    return result;
}

Matrix operator+ (const Matrix& matrix, const double& scalar) {
    Matrix result(matrix.nRows, matrix.nColumns);
    for (int i = 0; i < matrix.numberOfElements; i++) {
        result.data[i] = scalar +  matrix.data[i];
    }
    return result;
}

//Subtraction Operations
Matrix operator- (const Matrix& matrixOne, const Matrix& matrixTwo) {
    int oneRows = matrixOne.nRows;
    int twoRows = matrixTwo.nRows;
    int oneColumns = matrixOne.nColumns;
    int twoColumns = matrixTwo.nColumns;
    
    if (oneRows != twoRows || oneColumns != twoColumns) {
        throw std::invalid_argument("Matrix Dimension Mismatch");
    }

    Matrix result(oneRows, oneColumns);
    for (int i = 0; i < matrixOne.numberOfElements; i++) {
        result.data[i] = matrixOne.data[i] - matrixTwo.data[i];
    }
    return result;
}

Matrix operator- (const double& scalar, const Matrix& matrix) {
    Matrix result(matrix.nRows, matrix.nColumns);
    for (int i = 0; i < matrix.numberOfElements; i++) {
        result.data[i] = scalar -  matrix.data[i];
    }
    return result;
}

Matrix operator- (const Matrix& matrix, const double& scalar) {
    Matrix result(matrix.nRows, matrix.nColumns);
    for (int i = 0; i < matrix.numberOfElements; i++) {
        result.data[i] = matrix.data[i] - scalar;
    }
    return result;
}


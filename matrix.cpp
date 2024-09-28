#include "matrix.h"
#include <stdexcept>
#include <iomanip>
#include <math.h>

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

Matrix::Matrix(int rows, int columns, const std::vector<double> *inputData) {
     nRows = rows;
    nColumns = columns;
    numberOfElements = nRows * nColumns;
    data = new double[numberOfElements];

    for (int i = 0; i<numberOfElements; i++) {
        data[i] = inputData->at(i);
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

void Matrix::identity() {
    if (!isSquare()) {
        throw std::invalid_argument("Not a Square Matrix");
    }

    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nColumns; col++) {
            if (row == col) {
                data[index(row, col)] = 1.0;
            } else {
                data[index(row, col)] = 0.0;
            }
        }
    }
}

bool Matrix:: compare(const Matrix& matrix, double tol) {
     if (nRows != matrix.nRows || nColumns != matrix.nColumns) {
        return false;
    }
}

double Matrix::get(int row, int column){
    return data[index(row, column)];
}

bool Matrix::set(int row, int column, double val) {
    this->data[index(row, column)] = val;
    return true;
}

int Matrix::rowCount() {
    return nRows;
}

int Matrix::columnCount() {
    return nColumns;
}

bool Matrix::operator== (const Matrix& matrix) {
    if (this->nRows != matrix.nRows || this->nColumns != matrix.nColumns) {
        return false;
    }

    for (int i = 0; i < this->numberOfElements; i++) {
        if (this->data[i] != matrix.data[i]) {
            return false;
        }
    }

    return true;

}

//Matrix Operations
//
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

//Multplication Operations
Matrix operator* (const Matrix& matrixOne, const Matrix& matrixTwo) {
    if (matrixOne.nColumns != matrixTwo.nRows) {
        throw std::invalid_argument("Dimension Mismatch Exception");
    }
    Matrix result(matrixOne.nRows, matrixTwo.nColumns);
    
    for (int r = 0; r < matrixOne.nRows; r++) {
        for (int c = 0; c < matrixTwo.nColumns; c++)
        result.set(r, c, matrixOne.dotProduct(r, c, matrixTwo));
    }
    return result;
}

Matrix operator* (const double& scalar, const Matrix& matrix) {
    Matrix result(matrix.nRows, matrix.nColumns);
    for (int i = 0; i < matrix.numberOfElements; i++) {
        result.data[i] = scalar -  matrix.data[i];
    }
    return result;
}

Matrix operator* (const Matrix& matrix, const double& scalar) {
    Matrix result(matrix.nRows, matrix.nColumns);
    for (int i = 0; i < matrix.numberOfElements; i++) {
        result.data[i] = matrix.data[i] - scalar;
    }
    return result;
}

//private functions
int Matrix::index(int row, int column) const{
    if ((row >= nRows) || (column >= nColumns) || (row < 0) || (column <0)) {
        throw std::invalid_argument("Index Out of Bounds Exception");
    }
    return (row * nColumns) + column;
}

double Matrix::dotProduct(int row, int column, const Matrix& B) const{
    double sum = 0.0;
    for (int i = 0; i < nColumns; i++) {
        sum += data[index(row, i)] * B.data[B.index(i, column)];
    }
    return sum;
}

bool Matrix::isSquare() {
    return nRows == nColumns;
}

//row operations



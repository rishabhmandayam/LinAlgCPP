#include "matrix.h"

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

Matrix::~Matrix(){
    if (data != nullptr){
        delete[] data;
    }
}

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


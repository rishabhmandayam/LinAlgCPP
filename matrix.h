#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix{
    public:
        //constructors and deconstructors
        Matrix();
        Matrix(int rows, int columns);
        Matrix(int rows, int columns, const double* inputData);
        Matrix(const Matrix& copy); //copy matrix
        Matrix(int rows, int columns, const std::vector<double> *inputData);

        ~Matrix();
        
        //getters and settets
        bool resize(int rows, int columns);
        void identity();
        
        double get(int row, int column);
        bool set(int row, int column, double val);
        
        int rowCount();
        int columnCount();

        bool inverse();
        bool compare(const Matrix& matrix, double tol);

        bool operator== (const Matrix& matrix);

        //operations on matrix
        friend Matrix operator+ (const Matrix& matrixOne, const Matrix& matrixTwo);
        friend Matrix operator+ (const double& scalar, const Matrix& matrix);
        friend Matrix operator+ (const Matrix& matrix, const double& scalar);

        friend Matrix operator- (const Matrix& matrixOne, const Matrix& matrixTwo);
        friend Matrix operator- (const double& scalar, const Matrix& matrix);
        friend Matrix operator- (const Matrix& matrix, const double& scalar);

        friend Matrix operator* (const Matrix& matrixOne, const Matrix& matrixTwo);
        friend Matrix operator* (const double& scalar, const Matrix& matrix);
        friend Matrix operator* (const Matrix& matrix, const double& scalar);

        bool separate(Matrix *matrixOne, Matrix *matrixTwo, int column);
            
    private:
        int index(int row, int column) const;
        double dotProduct(int row, int column, const Matrix& B) const;

        bool isSquare();
        bool equalsWithTolerance(double itemOne, double itemTwo);
        
        //row operations
        void swapRow(int rowOne, int rowTwo);
        void multiplyRowandAdd(int rowOne, int rowTwo, double factor);
        void multiplyRow(int row, double factor);

        bool joinMatrix(const Matrix& matrix);
        int findMaxRow(int columnNumber, int startingRow);

        void printMatrix();

    private:
        double *data;
        int nRows; int nColumns; int numberOfElements;
};

#endif

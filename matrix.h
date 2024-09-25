#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
    public:
        //constructors and deconstructors
        Matrix();
        Matrix(int rows, int columns);
        Matrix(int rows, int columns, const double* inputData);
        Matrix(const Matrix& copy); //copy matrix

        ~Matrix();
        
        //getters and settets
        bool resize(int rows, int columns);

        double get(int row, int column);
        bool set(int row, int column, double val);
        
        int rowCount();
        int columnCount();

        bool operator== (const Matrix& matrix);

        //operations on matrix
        friend Matrix operator+ (const Matrix<double>& matrixOne, const Matrix<double>& matrixTwo);
        friend Matrix operator+ (const double& scalar, const Matrix<double>& matrix);
        friend Matrix operator+ (const Matrix<double>& matrix, const double& scalar);

        friend Matrix operator- (const Matrix<U>& matrixOne, const Matrix<U>& matrixTwo);
        friend Matrix operator- (const U& scalar, const Matrix<U>& matrix);
        friend Matrix operator- (const Matrix<U>& matrix, const U& scalar);

        friend Matrix operator* (const Matrix<U>& matrixOne, const Matrix<U>& matrixTwo);
        friend Matrix operator* (const U& scalar, const Matrix<U>& matrix);
        friend Matrix operator* (const Matrix<U>& matrix, const U& scalar);

    private:
        int index(int row, int column);

    private:
        double *data;
        int nRows; int nColumns; int numberOfElements;
};

#endif

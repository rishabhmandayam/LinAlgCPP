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
        friend Matrix operator+ (const Matrix& matrixOne, const Matrix& matrixTwo);
        friend Matrix operator+ (const double& scalar, const Matrix& matrix);
        friend Matrix operator+ (const Matrix& matrix, const double& scalar);

        friend Matrix operator- (const Matrix& matrixOne, const Matrix& matrixTwo);
        friend Matrix operator- (const double& scalar, const Matrix& matrix);
        friend Matrix operator- (const Matrix& matrix, const double& scalar);

        friend Matrix operator* (const Matrix& matrixOne, const Matrix& matrixTwo);
        friend Matrix operator* (const double& scalar, const Matrix& matrix);
        friend Matrix operator* (const Matrix& matrix, const double& scalar);

    private:
        int index(int row, int column);

    private:
        double *data;
        int nRows; int nColumns; int numberOfElements;
};

#endif

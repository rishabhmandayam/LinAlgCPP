#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

/**
 * @class Matrix
 * @brief A class that represents a mathematical matrix and supports various matrix operations.
 */
class Matrix{
    public:
        /**
         * @brief Default constructor. Initializes an empty matrix.
         */
        Matrix();
        
        /**
        * @brief Constructor to initialize a matrix with a specified number of rows and columns.
        * @param rows The number of rows in the matrix.
        * @param columns The number of columns in the matrix.
        */        
        Matrix(int rows, int columns);
        
        /**
        * @brief Constructor to initialize a matrix with data from a C-style array.
        * @param rows The number of rows in the matrix.
        * @param columns The number of columns in the matrix.
        * @param inputData Pointer to an array of doubles that contains the initial values.
        */
        Matrix(int rows, int columns, const double* inputData);
        
        /**
        * @brief Copy constructor. Creates a deep copy of another matrix.
        * @param copy The matrix to copy from.
        */
        Matrix(const Matrix& copy);
        
        /**
        * @brief Constructor to initialize a matrix with data from a std::vector.
        * @param rows The number of rows in the matrix.
        * @param columns The number of columns in the matrix.
        * @param inputData Pointer to a vector of doubles that contains the initial values.
        */
        Matrix(int rows, int columns, const std::vector<double> *inputData);
        
        /**
        * @brief Destructor. Cleans up dynamically allocated memory.
        */
        ~Matrix();
        
        /**
        * @brief Resizes the matrix to the specified number of rows and columns.
        * @param rows The new number of rows.
        * @param columns The new number of columns.
        * @return True if resizing is successful, otherwise false.
        */
        bool resize(int rows, int columns);
        
        /**
        * @brief Converts the matrix to an identity matrix. Only valid for square matrices.
        */
        void identity();
       
        /**
        * @brief Gets the value at the specified position in the matrix.
        * @param row The row index.
        * @param column The column index.
        * @return The value at the specified row and column.
        */
        double get(int row, int column);
       
        /**
        * @brief Sets the value at the specified position in the matrix.
        * @param row The row index.
        * @param column The column index.
        * @return True if the value was set succesfully, otherwsie false.
        */
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

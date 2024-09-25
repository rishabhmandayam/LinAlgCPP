#ifndef MATRIX_H
#define MATRIX_H

template <class T>
class Matrix{
    public:
        //constructors and deconstructors
        Matrix();
        Matrix(int rows, int columns);
        Matrix(int rows, int columns, const T* data);
        Matrix(const Matrix<T>& input);

        ~matrix();
        
        //getters and settets
        bool resize(int rows, int columns);

        T get(int row, int column);
        bool set(int row, into column, T val);
        
        int rowCount();
        int columnCount();

        bool operator== (const Matrix<2>& matrix);

        //





}

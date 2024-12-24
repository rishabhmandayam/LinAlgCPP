#include "matrix.hpp"
#include <algorithm>

namespace lin_alg {
    /* ###########
    Constructors
    ########### */ 
    mat::mat(): 
    n_rows(0), n_cols(0), data() {
        //empty matrix
    }

    mat::mat(size_t rows, size_t cols): 
    n_rows(rows), n_cols(cols), data(rows * cols, 0.0) {
        //all zeroes matrix
    }

    mat::mat(size_t rows, size_t cols, fill f, double val):
    n_rows(rows), n_cols(cols), data(rows * cols, 0.0) {
        switch(f) {
            case fill::zeros:
                std::fill(data.begin(), data.end(), 0.0);
                break;

            case fill::ones:
                std::fill(data.begin(), data.end(), 1.0);
                break;
            
            case fill::eye:
                {
                    std::fill(data.begin(), data.end(), 0.0);
                    size_t diag_len = (rows < cols) ? rows : cols;
                    for(size_t i = 0; i < diag_len; ++i) {
                        data[i * n_cols + i] = 1.0;
                    }
                }
                break;
            
            case fill::value:
                std::fill(data.begin(), data.end(), 1.0);
                break;
        }
    }

    mat::mat(const std::vector<double>& vec, bool is_col) 
    {
        if(is_col) {
            n_rows = vec.size();
            n_cols = 1;
        } else {
            n_rows = 1;
            n_cols = vec.size();
        }
        data = vec;
    }

   /* ###########
    Element Access
    ########### */
    double& mat::operator()(size_t r, size_t c) {
        return data[r * n_cols + c];
    }
    
    const double& mat::operator()(size_t r, size_t c) const {
        return data[r * n_cols + c];
    }
    
    /* ###########
    Helper Functions
    ########### */
    static void check_same_size(const mat& A, const mat& B, const char* op_name)
    {
        if (A.n_rows_() != B.n_rows_() || A.n_cols_() != B.n_cols_()) {
            throw std::runtime_error(std::string("Dimension mismatch in operator ") + op_name);
        }
    }

    mat operator+(const mat& A, const mat& B) {
        check_same_size(A, B, "+");
        mat result(A.n_rows_(), A.n_cols_());
        for (size_t i = 0; i < A.data.size(); ++i) {
            result.data[i] = A.data[i] + B.data[i];
        }
        return result;
    }

    mat operator+(const mat& A, const double scalar) {
        mat result(A.n_rows_(), A.n_cols_());
        for (size_t i = 0; i < A.data.size(); ++i) {
            result.data[i] = A.data[i] + scalar;
        }
        return result;
    }

    mat operator+(const double scalar, const mat& A) {
        return A + scalar;
    }
    
    mat operator-(const mat& A, const mat& B) {
        check_same_size(A, B, "+");
        mat result(A.n_rows_(), A.n_cols_());
        for (size_t i = 0; i < A.data.size(); ++i) {
            result.data[i] = A.data[i] - B.data[i];
        }
        return result;
    }

    mat operator-(const mat& A, const double scalar) {
        mat result(A.n_rows_(), A.n_cols_());
        for (size_t i = 0; i < A.data.size(); ++i) {
            result.data[i] = A.data[i] - scalar;
        }
        return result;
    }

    mat operator-(const double scalar, const mat& A) {
        return A - scalar;
    }





} //namespace lin_alg
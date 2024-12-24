#ifndef LA_MATRIX_HPP
#define LA_MATRIX_HPP

#include <vector>
#include <cstddef>

namespace lin_alg {
    enum class fill {
        zeros,
        ones,
        eye,
        value
    };

    class mat {
        std::vector<double> data;
        private:
            size_t n_rows;
            size_t n_cols;
        public:
            //Default constructor -> empty matrix (0 x 0)
            mat();

            //Constructor -> specify n_rows, n_cols (initialized to 0)
            mat(size_t rows, size_t cols);

            //Constructor -> specify n_rows, n_cols, fill type (and optional double for fill::value)
            mat(size_t rows, size_t cols, fill f, double val = 0.0);

            //Constructor -> build row or column vector from std::vector<double>
            mat(const std::vector<double>& vec, bool is_col = true);

            // getters
            size_t n_rows_() const { return n_rows; }
            size_t n_cols_() const { return n_cols; }
            size_t n_elem()  const { return data.size(); }

            double& operator()(size_t r, size_t c);
            const double& operator()(size_t r, size_t c) const;

            //
            //  Inline definitions: operator overloads 
            //
            //
            friend mat operator+(const mat& A, const mat& B);
            friend mat operator+(const mat& A, double scalar);
            friend mat operator+(double scalar, const mat& A);

            friend mat operator-(const mat& A, const mat& B);
            friend mat operator-(const mat& A, double scalar);
            friend mat operator-(double scalar, const mat& A);

            //Schur Multiplication
            friend mat operator%(const mat& A, const mat& B);
            friend mat operator%(const mat& A, double scalar);
            friend mat operator%(double scalar, const mat& A);

            // Element-wise division
            friend mat operator/(const mat& A, const mat& B);
            friend mat operator/(const mat& A, double scalar);
            friend mat operator/(double scalar, const mat& A);

            // Equality comparisons -> element-wise 1.0 or 0.0
            friend mat operator==(const mat& A, const mat& B);
            friend mat operator==(const mat& A, double scalar);

            friend mat operator!=(const mat& A, const mat& B);
            friend mat operator!=(const mat& A, double scalar);
            
            friend mat operator<=(const mat& A, const mat& B);
            friend mat operator<=(const mat& A, double scalar);
            
            friend mat operator>=(const mat& A, const mat& B);
            friend mat operator>=(const mat& A, double scalar);
            
            friend mat operator<(const mat& A, const mat& B);
            
            friend mat operator>(const mat& A, const mat& B);
    };
}

#endif

#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace lin_alg;

/**
 * @brief Helper function to check all elements of a matrix are close to a value
 * within a given tolerance
 *
 * @param M: the matrix to check 
 * @param value: the expected value of each element
 * @param tol: the absolute value tolerance for floats
 */

static void expect_all_close(const mat& M, double value, double tol = 1e-9) {
    for (size_t r = 0; r < M.n_rows_(); ++r) {
        for (size_t c = 0; c < M.n_cols_(); ++c) {
            EXPECT_NEAR(M(r,c), value, tol);
        }
    }
}

TEST(MatrixTest, DefaultConstructor) {
    mat M; //0x0
    EXPECT_EQ(M.n_rows_(), 0);
    EXPECT_EQ(M.n_cols_(), 0);
}

TEST(MatrixTest, SizeConstructor) {
    mat M(3,5);
    EXPECT_EQ(M.n_rows_(), 3);
    EXPECT_EQ(M.n_cols_(), 5);
    expect_all_close(M, 0.0);
}

TEST(MatrixTest, FillConstructorZeros) {
    mat M(4, 4, fill::zeros);
    EXPECT_EQ(M.n_rows_(), 4);
    EXPECT_EQ(M.n_cols_(), 4);
    expect_all_close(M, 0.0);
}

TEST(MatrixTest, FillConstructorOnes) {
    mat M(4, 4, fill::ones);
    EXPECT_EQ(M.n_rows_(), 4);
    EXPECT_EQ(M.n_cols_(), 4);
    expect_all_close(M, 1.0);
}

TEST(MatrixTest, FillConstructorValue) {
    mat M(2, 3, fill::value, 3.14);
    expect_all_close(M, 3.14);
}

TEST(MatrixTest, FillConstructorEye) {
    mat M(3, 5, fill::eye);
    
    for (size_t r = 0; r < M.n_rows_(); ++r) {
        for (size_t c = 0; c < M.n_cols_(); ++c) {
            if (r == c) {
                EXPECT_NEAR(M(r , c), 1.0, 1e-9);
            } else {
                EXPECT_NEAR(M(r , c), 0.0, 1e-9);
            }
        }
    }
}

TEST(MatrixTest, VectorConstructorCol) {
    std::vector<double> v{1.0, 2.0, 3.0};
    mat M(v, /*is_col=*/true);
    EXPECT_EQ(M.n_rows_(), 3);
    EXPECT_EQ(M.n_cols_(), 1);
    EXPECT_NEAR(M(0,0), 1.0, 1e-9);
    EXPECT_NEAR(M(1,0), 2.0, 1e-9);
    EXPECT_NEAR(M(2,0), 3.0, 1e-9);
}

TEST(MatrixTest, VectorConstructorRow) {
    std::vector<double> v{1.0, 2.0, 3.0};
    mat M(v, /*is_col=*/false);
    EXPECT_EQ(M.n_rows_(), 1);
    EXPECT_EQ(M.n_cols_(), 3);
    EXPECT_NEAR(M(0,0), 1.0, 1e-9);
    EXPECT_NEAR(M(0,1), 2.0, 1e-9);
    EXPECT_NEAR(M(0,2), 3.0, 1e-9);
}



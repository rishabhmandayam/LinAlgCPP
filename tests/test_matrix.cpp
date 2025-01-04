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

TEST(MatrixTest, ElementAccess) {
    mat M(2, 2, fill::zeros);
    M(0,0) = 10.5;
    M(1,1) = -3.3;

    EXPECT_NEAR(M(0,0), 10.5, 1e-9);
    EXPECT_NEAR(M(1,1), -3.3, 1e-9);
}

TEST(MatrixTest, OperatorPlusMatrix) {
    mat A(2, 2, fill::ones); // all 1s
    mat B(2, 2, fill::ones); // all 1s
    mat C = A + B;           // all 2s
    expect_all_close(C, 2.0);
}

TEST(MatrixTest, OperatorPlusScalar) {
    mat A(2, 2, fill::ones); 
    mat C = A + 5.0;         // all 6s
    expect_all_close(C, 6.0);
}

TEST(MatrixTest, OperatorPlusDimensionMismatch) {
    mat A(2, 2, fill::ones);
    mat B(3, 3, fill::ones);
    EXPECT_THROW({ mat C = A + B; }, std::runtime_error);
}

TEST(MatrixTest, OperatorMinusMatrix) {
    mat A(2, 2, fill::ones);
    mat B(2, 2, fill::ones);
    mat C = A - B; // all 0s
    expect_all_close(C, 0.0);
}

TEST(MatrixTest, OperatorMinusScalar) {
    mat A(2, 2, fill::ones);
    mat C = A - 5.0; // all -4s
    expect_all_close(C, -4.0);
}

TEST(MatrixTest, OperatorSchurMultiplyMatrix) {
    mat A(2, 2, fill::ones);           
    mat B(2, 2, fill::value, 2.0);     
    mat C = A % B;                     
    expect_all_close(C, 2.0);
}

TEST(MatrixTest, OperatorSchurMultiplyScalar) {
    mat A(2, 2, fill::ones);
    mat C = A % 5.0; // all 5
    expect_all_close(C, 5.0);
}

TEST(MatrixTest, OperatorDivideMatrix) {
    mat A(2, 2, fill::value, 10.0); // all 10
    mat B(2, 2, fill::value, 2.0);  // all 2
    mat C = A / B; // all 5
    expect_all_close(C, 5.0);
}

TEST(MatrixTest, OperatorDivideScalar) {
    mat A(2, 2, fill::value, 10.0);
    mat C = A / 2.0; // all 5
    expect_all_close(C, 5.0);
}

TEST(MatrixTest, OperatorDivideScalarLeft) {
    // scalar / mat
    mat A(2, 2, fill::value, 2.0); // all 2
    mat C = 10.0 / A;              // all 5
    expect_all_close(C, 5.0);
}


TEST(MatrixTest, OperatorEqualMatrix) {
    mat A(2, 2, fill::value, 3.0);
    mat B(2, 2, fill::value, 3.0);
    mat C = A == B; // all 1.0
    expect_all_close(C, 1.0);
}

TEST(MatrixTest, OperatorEqualScalar) {
    mat A(2, 2, fill::value, 3.0);
    mat C = A == 3.0; // all 1.0
    expect_all_close(C, 1.0);

    mat D = A == 2.0; // all 0.0
    expect_all_close(D, 0.0);
}

TEST(MatrixTest, OperatorNotEqualMatrix) {
    mat A(2, 2, fill::value, 5.0);
    mat B(2, 2, fill::value, 5.0);
    mat C = A != B; // all 0.0
    expect_all_close(C, 0.0);
}

TEST(MatrixTest, OperatorLessThanMatrix) {
    mat A(2, 2, fill::value, 1.0);
    mat B(2, 2, fill::value, 2.0);
    mat C = A < B; // all 1.0
    expect_all_close(C, 1.0);
}

TEST(MatrixTest, OperatorGreaterThanScalar) {
    mat A(2, 2, fill::value, 3.0);
    mat C = A > 2.0; // all 1.0
    expect_all_close(C, 1.0);
}

//
// Matrix Multiplication (Blocked)
//
TEST(MatrixTest, OperatorMultiplyMatrix) {
    // 2x3 * 3x2 -> 2x2
    mat A(2, 3, fill::zeros);
    A(0,0) = 1; A(0,1) = 2; A(0,2) = 3;
    A(1,0) = 4; A(1,1) = 5; A(1,2) = 6;

    mat B(3, 2, fill::zeros);
    B(0,0) =  7; B(0,1) =  8;
    B(1,0) =  9; B(1,1) = 10;
    B(2,0) = 11; B(2,1) = 12;

    // Expect A*B = [58, 64
    //              139,154]
    mat C = A * B;
    EXPECT_EQ(C.n_rows_(), 2);
    EXPECT_EQ(C.n_cols_(), 2);

    EXPECT_NEAR(C(0,0),  58.0, 1e-9);
    EXPECT_NEAR(C(0,1),  64.0, 1e-9);
    EXPECT_NEAR(C(1,0), 139.0, 1e-9);
    EXPECT_NEAR(C(1,1), 154.0, 1e-9);
}

TEST(MatrixTest, OperatorMultiplyDimensionMismatch) {
    mat A(2, 3, fill::ones);
    mat B(2, 2, fill::ones); 
    // Incompatible shape: A is 2x3, B is 2x2 => can't multiply
    EXPECT_THROW({ mat C = A * B; }, std::runtime_error);
}
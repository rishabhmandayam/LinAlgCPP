#include <iostream>
#include "include/matrix.hpp"

int main() {
    using namespace lin_alg;
    mat A;
    std::cout << "A: " << A.n_rows_() << " x " << A.n_cols_() << "\n";

    mat B(3, 4);
    std::cout << "A: " << A.n_rows_() << " x " << A.n_cols_() << "\n";

    return 0;
}

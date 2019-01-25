//
// Created by Chander Raja on 2019-01-24.
//

// A simple program that computes the square root of a number
#include <stdio.h>
#include "matrix.h"

using namespace mycorp;

///
/// \param argc count of arguments
/// \param argv array of arguments
/// \return exit code
int main (int argc, char *argv[])
{
    Matrix<double, 2, 2> m1({0.1, 0.2, 0.3, 0.4});
    Matrix<double, 2, 2> m2({1., 2., 3., 4.});


    auto * prod = m1 * m2;

    Matrix<double, 2, 2> expected({0.7, 1.0, 1.5, 2.2});

    if (*prod == expected) {
        printf("test passed\n");
    }

    for (unsigned int row = 0; row < prod->rows(); ++row) {
        for (unsigned int col = 0; col < prod->columns(); ++col) {
            printf("%lf ", (*prod)[{row, col}]);
        }
        printf("\n");
    }


    delete prod;

    return 0;
}
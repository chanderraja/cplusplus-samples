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
    Matrix<double, 20, 3> m1;
    Matrix<double, 3, 32> m2;

    auto * prod = m1 * m2;

    printf("rows = %d cols = %d\n", prod->rows(), prod->columns());

    return 0;
}
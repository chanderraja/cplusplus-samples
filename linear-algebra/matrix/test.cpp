//
// Created by Chander Raja on 2019-01-24.
//

// A simple program that computes the square root of a number
#include <iostream>
#include "matrix.h"

using namespace LinearAlgebraLib;
using namespace std;

///
/// \param argc count of arguments
/// \param argv array of arguments
/// \return exit code
int main (int argc, char *argv[])
{

    Matrix<float, 2, 2> m1({0.1, 0.2, 0.3, 0.4});
    Matrix<float, 2, 2> m2({1., 2., 3., 4.});

    Matrix<float, 2, 2> expected({0.7, 1.0, 1.5, 2.2});

    auto * prod = m1 * m2;

    bool passed = (*prod == expected);


    printf("passed = %d\n", passed);

    cout << "prod = " << endl;
    cout << *prod;
    cout << "expected = " << endl;
    cout << expected;
    delete prod;


    Matrix<int, 2, 4> mi1({1, 4, 6, 10, 2, 7, 5, 3});

    Matrix<int, 4, 3> mi2({1, 4, 6, 2, 7, 5, 9, 0, 11, 3, 1, 0});

    Matrix<int, 2, 3> mi_exp({93, 42, 92, 70, 60, 102});

    cout << "mi1[" << mi1.rows() << "," << mi1.columns() << "] = " << endl;
    cout << mi1 << endl;
    cout << "mi2[" << mi2.rows() << "," << mi2.columns() << "] = " << endl;
    cout << mi2 << endl;

    auto * prod2 = mi1 * mi2;

    passed = (*prod2 == mi_exp);

    printf("passed = %d\n", passed);

    cout << "prod = " << endl;
    cout << *prod2;
    cout << "expected = " << endl;
    cout << mi_exp;
    delete prod2;


    auto *transposed = mi1.transpose();
    cout << "transposed mi1 = " << endl;
    cout << *transposed;



    return 0;
}
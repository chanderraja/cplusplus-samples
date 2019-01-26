//
// Created by Chander Raja on 2019-01-24.
//

// A simple program that computes the square root of a number
#include <iostream>
#include "matrix.h"

using namespace mycorp;
using namespace std;

namespace mycorp {

}

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

    Matrix<int, 2, 2> mi1({-1, 2, -3, 4});
    Matrix<int, 2, 2> mi2({5, -6, 7, -8});

    Matrix<int, 2, 2> mi_exp({9, -10, 13, -14});

    auto * prod2 = mi1 * mi2;

    passed = (*prod2 == mi_exp);

    printf("passed = %d\n", passed);

    cout << "prod = " << endl;
    cout << *prod2;
    cout << "expected = " << endl;
    cout << mi_exp;


    delete prod2;
    delete prod;

    return 0;
}
// ===== Established 2024-04-07 - 2024-0X-0X ========
//
//  Functionality: Tests out each feature of the SVD
//
// ==================================================



#include "helper.hpp"
#include "construct.hpp"
#include <iostream>
#include <cassert>

#define MESSAGE_SUCCESS "Success"
#define MESSAGE_FAILURE "Failure"
#define CON_MATRIX_PASS "Construct Matrix Passes"
#define CON_MATRIX_FAIL "Construct Matrix Fails"
#define STATUS FALSE



/**
 * Tests the construct_matrix individually
 * @return none
*/
void test_construct_matrix() {
    vector<double> row_vec = {1.0, 0.0, 0.0, 1.0};
    vector<vector<double>> exp_matrix = {{1.0, 0.0}, {0.0, 1.0}};
    vector<vector<double>> act_matrix = construct_matrix(row_vec);
    print_matrix(act_matrix);
    assert(exp_matrix == act_matrix && CON_MATRIX_FAIL);
    
    cout << CON_MATRIX_PASS << endl;
}



/**
 * Enables for user input of a vector
 * @param argc
 * @param argv
 * @return 0 for no errors, otherwise 1.
*/
int main() {

    cout << "here" << endl;
    test_construct_matrix();

    return 0;
}

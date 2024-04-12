// ===== Established 2024-04-07 - 2024-0X-0X ========
//
//  Functionality: Tests out each feature of the SVD
//
// ==================================================



#include "helper.hpp"
#include "input.hpp"
#include "construct.hpp"
#include "operation.hpp"
#include <iostream>
#include <string>
#include <cassert>

#define MESSAGE_SUCCESS "Success"
#define MESSAGE_FAILURE "Failure"
#define CON_MATRIX_PASS "Construct Matrix Passes"
#define CON_MATRIX_FAIL "Construct Matrix Fails"
#define CSV_TO_DATA_PASS "CSV converted"
#define CSV_TO_DATA_FAIL "CSV was unable to be converted"
#define TRANSPOSE_PASS "Transpose successful"
#define TRANSPOSE_FAIL "Transpose unsuccessful"
#define STATUS FALSE



/**
 * Tests the construct_matrix individually
 * @return none
*/
void test_construct_matrix() {
    vector<double> vec = {1.0, 0.0, 0.0, 1.0};
    vector<vector<double>> exp_matrix = {{1.0, 0.0}, {0.0, 1.0}};
    vector<vector<double>> act_matrix = construct_matrix(vec);
    print_matrix(act_matrix);

    assert(exp_matrix == act_matrix && CON_MATRIX_FAIL);
    cout << CON_MATRIX_PASS << endl;
}



/**
 * Tests the csvToData
 * @param path The location of the csv file.
 * @return none
*/
void test_csvToData(char* & path) {
    vector<vector<double>> exp_data = {{1.0, 0.0, 0.0, 1.0}};
    vector<vector<double>> act_data = csvToData(path);
    vector<vector<double>> exp_matrix = construct_matrix(exp_data[0]);
    print_matrix(exp_matrix);

    vector<vector<double>> act_matrix = construct_matrix(act_data[0]);
    print_matrix(act_matrix);

    assert(exp_data == act_data && CSV_TO_DATA_FAIL);
    cout << CSV_TO_DATA_PASS << endl;
}



/**
 * Tests the csvToData
 * @param path The location of the csv file.
 * @return none
*/
void test_csvToData_two(char* & path) {
    vector<vector<double>> exp_data = {{2.0, 0.0, 0.0, 2.0},
    {3.0, 3.0, 3.0, 3.0}};
    vector<vector<double>> act_data = csvToData(path);

    vector<vector<double>> exp_matrix = construct_matrix(exp_data[0]);
    print_matrix(exp_matrix);
    vector<vector<double>> exp_matrix_two = construct_matrix(exp_data[1]);
    print_matrix(exp_matrix_two);

    vector<vector<double>> act_matrix = construct_matrix(act_data[0]);
    print_matrix(act_matrix);
    vector<vector<double>> act_matrix_two = construct_matrix(act_data[1]);
    print_matrix(act_matrix_two);

    assert(exp_data == act_data && CSV_TO_DATA_FAIL);
    cout << CSV_TO_DATA_PASS << endl;
}



/**
 * Checks the transposed matrix
 * @return nothing
*/
void test_transpose() {
    vector<vector<double>> matrix = {{1.0, 2.0}, {3.0, 4.0}};
    vector<vector<double>> exp_matrix = {{1.0, 3.0}, {2.0, 4.0}};
    vector<vector<double>> act_matrix;

    act_matrix = transpose(matrix);

    assert(exp_matrix == act_matrix && TRANSPOSE_FAIL);
    cout << TRANSPOSE_PASS << endl;
}



/**
 * Enables for user input of a vector
 * @param argc
 * @param argv
 * @return 0 for no errors, otherwise 1.
*/
int main(int argc, char** argv) {
    // test_construct_matrix();
    // test_csvToData(argv[1]);
    // test_csvToData_two(argv[1]);
    test_transpose();

    return 0;
}

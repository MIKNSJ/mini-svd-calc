// ===== Established 2024-04-07 - 2024-0X-0X =====
//
//  Functionality: Constructs the matrix.
//
// ===============================================



#include "construct.hpp"
#include <iostream>



vector<vector<double>> construct_matrix(vector<double> row_vec) {
    vector<vector<double>> matrix;
    vector<double> col_vec_one;
    vector<double> col_vec_two;
    
    for (int i = 0; i < (int)row_vec.size(); i++) {
        if (i < 2) {
            col_vec_one.push_back(row_vec[i]);
        } else {
            col_vec_two.push_back(row_vec[i]);
        }
    }

    matrix.push_back(col_vec_one);
    matrix.push_back(col_vec_two);

    return matrix;
}
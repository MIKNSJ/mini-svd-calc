// ===== Established 2024-04-11 - 2024-0X-0X ========
//
//  Functionality: Provides matrix operations
//
// ==================================================


#include "operation.hpp"
#include <iostream>



/**
 * Finds eigenvalues using quadratic formula
 * @param
 * @return Eigenvalues of a matrix
*/



/**
 * Transposes a matrix
 * @param matrix The original matrix
 * @return A transposed matrix
*/
vector<vector<double>> transpose(vector<vector<double>> matrix) {
    vector<vector<double>> transposed_matrix;
    vector<double> col_vec;
    vector<double> col_vec_two;

    for (int i = 0; i < (int)matrix.size(); i++) {
        for (int j = 0; j < (int)matrix[i].size(); j++) {
            if (j % 2 == 0) {
                col_vec.push_back(matrix[i][j]);
            } else {
                col_vec_two.push_back(matrix[i][j]);
            }
        }
    }

    transposed_matrix.push_back(col_vec);
    transposed_matrix.push_back(col_vec_two);

    return transposed_matrix;
}



/**
 * Matrix muliplication
 * @param
 * @return The product matrix between two
*/



/**
 * RREF a matrix
 * @param
 * @return A RREF matrix
*/



/**
 * Finds the null space of a matrix
 * @param
 * @return A basis of a matrix
*/



/**
 * Finds u-vectors
 * @param
 * @return A set of u-vectors to form an orthogonal matrix
*/



/**
 * Normalizes a vector
 * @param
 * @return A normalized/unit vector
*/

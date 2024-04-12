// ===== Established 2024-04-11 - 2024-0X-0X ========
//
//  Functionality: Provides matrix operations.
//
// ==================================================


#include "construct.hpp"
#include "operation.hpp"
#include <iostream>
#include <cmath>



/**
 * Finds the partial determinant of a matrix.
 * @param
 * @return A characteristic polynomial.
*/



/**
 * Finds eigenvalues of a matrix.
 * @param
 * @return The eigenvalues of a matrix.
*/



/**
 * Transposes a matrix.
 * @param matrix The original matrix.
 * @return A transposed matrix.
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
 * @param A Matrix factor
 * @param B Another matrix factor
 * @return The product matrix between A and B.
*/
vector<vector<double>> multiply(vector<vector<double>> A,
    vector<vector<double>> B) {
    vector<double> product_vec;
    vector<vector<double>> product_matrix;
    vector<double> B_col_vec;
    vector<double> B_col_vec_two;
    double leftEntry, rightEntry;

    for (int i = 0; i < (int)B.size(); i++) {
        for (int j = 0; j < (int)B[i].size(); j++) {
            if (j % 2 == 0) {
                B_col_vec.push_back(B[i][j]);
            } else {
                B_col_vec_two.push_back(B[i][j]);
            }
        }
    }

    for (int i = 0; i < (int)A.size(); i++) {
        leftEntry = 0;
        rightEntry = 0;

        for (int j = 0; j < (int)A[i].size(); j++) {
            leftEntry += A[i][j] * B_col_vec[j];
            rightEntry += A[i][j] * B_col_vec_two[j];
        }

        product_vec.push_back(leftEntry);
        product_vec.push_back(rightEntry);
    }

    product_matrix = construct_matrix(product_vec);

    return product_matrix;
}



/**
 * RREF a matrix
 * @param
 * @return A RREF matrix
*/



/**
 * Finds the null space of a matrix.
 * @param
 * @return A basis of a matrix.
*/



/**
 * Finds u-vectors.
 * @param
 * @return A set of u-vectors to form an orthogonal matrix.
*/



/**
 * Normalizes a vector.
 * @param
 * @return A normalized/unit vector.
*/

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
 * @param matrix A matrix
 * @return A characteristic polynomial.
*/
vector<double> determinant(vector<vector<double>> matrix) {
    vector<double> char_poly;
    double a, ab, c;

    // p(x) = ax^2 + bx + c, ad - bc, where diagonals are n - \lambda
    a = 1.0;
    ab = (-1.0 * matrix[0][0]) + (-1.0 * matrix[1][1]);
    c = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    char_poly.push_back(a);
    char_poly.push_back(ab);
    char_poly.push_back(c);

    return char_poly;
}



/**
 * Finds the eigenvalues of a matrix.
 * NOTE: We are only considering real eigenvalues.
 * @param char_poly The characteristic polynomial.
 * @return The eigenvalues of a matrix.
*/
vector<double> find_eigenvalues(vector<double> char_poly) {
    vector<double> eigenvalues;
    double discriminant;
    double a, b;

    discriminant = pow(char_poly[1], 2) - (4.0 * char_poly[0] * char_poly[2]);

    if (discriminant < 0) {
        return eigenvalues;
    } else if (discriminant == 0) {
        eigenvalues.push_back(-char_poly[1] / (2.0 * char_poly[0]));
        return eigenvalues;
    } else {
        a = ((-char_poly[1] - discriminant) / (2.0 * char_poly[0]));
        b = ((-char_poly[1] + discriminant) / (2.0 * char_poly[0]));

        if (a >= b) {
            eigenvalues.push_back(a);
            eigenvalues.push_back(b);
        } else {
            eigenvalues.push_back(b);
            eigenvalues.push_back(a);
        }

        return eigenvalues;
    }
}



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

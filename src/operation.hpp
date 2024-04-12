// ===== Established 2024-04-11 - 2024-0X-0X ========
//
//  Functionality: Provides matrix operations.
//
// ==================================================



#ifndef operation_hpp
#define operation_hpp

#include <vector>
using namespace std;



/**
 * Finds the partial determinant of a matrix.
 * @param
 * @return A characteristic polynomial.
*/



/**
 * Finds eigenvalues using quadratic formula
 * @param
 * @return Eigenvalues of a matrix
*/



/**
 * Transposes a matrix.
 * @param matrix The original matrix.
 * @return A transposed matrix.
*/
vector<vector<double>> transpose(vector<vector<double>> matrix);



/**
 * Matrix muliplication
 * @param A Matrix factor
 * @param B Another matrix factor
 * @return The product matrix between A and B.
*/
vector<vector<double>> multiply(vector<vector<double>> A,
    vector<vector<double>> B);



/**
 * RREF a matrix.
 * @param
 * @return A RREF matrix.
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



#endif
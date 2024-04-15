// ===== Established 2024-04-14 - 2024-0X-0X ========
//
//  Functionality: Builds the SVD.
//
// ==================================================



#include "helper.hpp"
#include "input.hpp"
#include "construct.hpp"
#include "operation.hpp"
#include <iostream>
#include <cmath>



/**
 * Enables for user input of a vector
 * @param argc number of arguments
 * @param argv the command and csv file
 * @return 0 for no errors, otherwise 1.
*/
int main(int argc, char** argv) {
    vector<vector<double>> list = csvToData(argv[1]);

    for (int i = 0; i < (int)list.size(); i++) {
        vector<vector<double>> A = construct_matrix(list[i]);
        vector<vector<double>> A_trans = transpose(A);
        vector<vector<double>> ATA = multiply(A_trans, A);
        vector<vector<double>> ATA_V;
        vector<vector<double>> rref_ATA_V;

        double s_value;
        vector<double> v_0;
        vector<double> v_1;
        vector<double> u_0;
        vector<double> u_1;

        vector<vector<double>> u_matrix;
        vector<vector<double>> s_matrix;
        vector<vector<double>> v_matrix;

        // check if zero matrix
        double zero_cnt = 0;

        // loop through entries
        for (int i = 0; i < (int)A.size(); i++) {
            for (int j = 0; j < (int)A.size(); j++) {
                if (A[i][j] == 0) {
                    zero_cnt++;
                }
            }
        }

        // all entries are zero, early termination
        if (zero_cnt == 4) {
            u_matrix = {{1, 0}, {0, 1}};
            s_matrix = {{0, 0}, {0, 0}};
            v_matrix = {{1, 0}, {0, 1}};

            cout << "A matrix =" << endl;
            print_matrix(A);
            cout << " " << endl;

            cout << "U matrix =" << endl;
            print_matrix(u_matrix);
            cout << " " << endl;

            cout << "S matrix =" << endl;
            print_matrix(s_matrix);
            cout << " " << endl;

            cout << "V^T matrix =" << endl;
            print_matrix(v_matrix);

            return 0;
        }

        vector<double> char_poly = determinant(ATA);
        vector<double> eigenvalues = find_eigenvalues(char_poly);

        // check if non-real matrix
        if (eigenvalues.size() == 0) {
            cout << "Please rerun the program and enter a real matrix."
                << endl;
            return 0;
        }

        for (int j = 0; j < (int)eigenvalues.size(); j++) {
            s_value = sqrt(eigenvalues[j]);
            ATA_V = ATA;
            ATA_V[0][0] = ATA_V[0][0] - eigenvalues[j];
            ATA_V[1][1] = ATA_V[1][1] - eigenvalues[j];
            rref_ATA_V = rref(ATA_V);

            if (j == 0) {
                v_0 = null_space(rref_ATA_V);
                u_0 = find_u_vec(s_value, A, v_0);
                v_0 = normalize(v_0);
                u_0 = normalize(u_0);

                v_matrix.push_back(v_0);
                u_matrix.push_back(u_0);

            } else {
                v_1 = null_space(rref_ATA_V);
                if (s_value != 0) {
                    u_1 = find_u_vec(s_value, A, v_1);
                } else {
                    u_1 = v_1;
                }

                v_1 = normalize(v_1);
                u_1 = normalize(u_1);

                v_matrix.push_back(v_1);
                u_matrix.push_back(u_1);
            }

        }

        s_matrix = {{sqrt(eigenvalues[0]), 0.0}, {0.0, sqrt(eigenvalues[1])}};
        u_matrix = transpose(u_matrix);

        cout << "A matrix =" << endl;
        print_matrix(A);
        cout << " " << endl;

        cout << "U matrix =" << endl;
        print_matrix(u_matrix);
        cout << " " << endl;

        cout << "S matrix =" << endl;
        print_matrix(s_matrix);
        cout << " " << endl;

        cout << "V^T matrix =" << endl;
        print_matrix(v_matrix);
        cout << " " << endl;
    }

    return 0;
}
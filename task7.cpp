#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Standard matrix multiplication
vector<vector<int>> standardMultiply(vector<vector<int>> A,
                                     vector<vector<int>> B) {

    int n = A.size();

    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

// Add two matrices
vector<vector<int>> addMatrix(vector<vector<int>> A,
                               vector<vector<int>> B) {

    int n = A.size();

    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

// Subtract two matrices
vector<vector<int>> subtractMatrix(vector<vector<int>> A,
                                    vector<vector<int>> B) {

    int n = A.size();

    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

// Strassen's Matrix Multiplication
vector<vector<int>> strassenMultiply(vector<vector<int>> A,
                                      vector<vector<int>> B) {

    int n = A.size();

    // Base case: 1x1 matrix
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int half = n / 2;

    // Divide matrices into four submatrices
    vector<vector<int>> A11(half, vector<int>(half));
    vector<vector<int>> A12(half, vector<int>(half));
    vector<vector<int>> A21(half, vector<int>(half));
    vector<vector<int>> A22(half, vector<int>(half));

    vector<vector<int>> B11(half, vector<int>(half));
    vector<vector<int>> B12(half, vector<int>(half));
    vector<vector<int>> B21(half, vector<int>(half));
    vector<vector<int>> B22(half, vector<int>(half));

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {

            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // Seven Strassen products
    vector<vector<int>> M1 =
        strassenMultiply(addMatrix(A11, A22),
                         addMatrix(B11, B22));

    vector<vector<int>> M2 =
        strassenMultiply(addMatrix(A21, A22), B11);

    vector<vector<int>> M3 =
        strassenMultiply(A11, subtractMatrix(B12, B22));

    vector<vector<int>> M4 =
        strassenMultiply(A22, subtractMatrix(B21, B11));

    vector<vector<int>> M5 =
        strassenMultiply(addMatrix(A11, A12), B22);

    vector<vector<int>> M6 =
        strassenMultiply(subtractMatrix(A21, A11),
                         addMatrix(B11, B12));

    vector<vector<int>> M7 =
        strassenMultiply(subtractMatrix(A12, A22),
                         addMatrix(B21, B22));

    // Calculate result submatrices
    vector<vector<int>> C11 =
        addMatrix(subtractMatrix(addMatrix(M1, M4), M5), M7);

    vector<vector<int>> C12 =
        addMatrix(M3, M5);

    vector<vector<int>> C21 =
        addMatrix(M2, M4);

    vector<vector<int>> C22 =
        addMatrix(subtractMatrix(addMatrix(M1, M3), M2), M6);

    // Combine result
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {

            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }

    return C;
}

// Check if two matrices are equal
bool matricesEqual(vector<vector<int>> A,
                   vector<vector<int>> B) {

    int n = A.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != B[i][j]) {
                return false;
            }
        }
    }

    return true;
}

// Print a matrix
void printMatrix(vector<vector<int>> matrix) {

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    // Test 1: 2x2 matrices
    vector<vector<int>> A2 = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> B2 = {
        {5, 6},
        {7, 8}
    };

    vector<vector<int>> standard2 = standardMultiply(A2, B2);
    vector<vector<int>> strassen2 = strassenMultiply(A2, B2);

    cout << "Test 1: 2x2 Matrix" << endl;
    printMatrix(strassen2);

    cout << "2x2 Result: "
         << (matricesEqual(standard2, strassen2) ? "PASS" : "FAIL")
         << endl << endl;


    // Test 2: 4x4 matrices
    vector<vector<int>> A4 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<vector<int>> B4 = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };

    vector<vector<int>> standard4 = standardMultiply(A4, B4);
    vector<vector<int>> strassen4 = strassenMultiply(A4, B4);

    cout << "Test 2: 4x4 Matrix" << endl;
    printMatrix(strassen4);

    cout << "4x4 Result: "
         << (matricesEqual(standard4, strassen4) ? "PASS" : "FAIL")
         << endl << endl;


    // Test 3: Random values
    vector<vector<int>> randomA = {
        {2, 1, 3, 4},
        {5, 2, 1, 3},
        {4, 3, 2, 1},
        {1, 4, 5, 2}
    };

    vector<vector<int>> randomB = {
        {1, 3, 2, 4},
        {2, 1, 4, 3},
        {3, 2, 1, 5},
        {4, 5, 3, 2}
    };

    vector<vector<int>> standardRandom =
        standardMultiply(randomA, randomB);

    vector<vector<int>> strassenRandom =
        strassenMultiply(randomA, randomB);

    cout << "Test 3: Random Values" << endl;

    cout << "Random Test Result: "
         << (matricesEqual(standardRandom, strassenRandom)
             ? "PASS"
             : "FAIL")
         << endl;

    return 0;
}

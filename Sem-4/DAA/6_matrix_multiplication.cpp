#include <iostream>
#include <vector>
using namespace std;

// Function to add two matrices
vector<vector<int>> matrixAddition(const vector<vector<int>>& A, const vector<vector<int>>& B, int& steps) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
            steps++; // Increment steps counter
        }
    }
    return C;
}

// Function to subtract two matrices
vector<vector<int>> matrixSubtraction(const vector<vector<int>>& A, const vector<vector<int>>& B, int& steps) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
            steps++; // Increment steps counter
        }
    }
    return C;
}

// Function to multiply two matrices using brute force method
vector<vector<int>> normalMatrixMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B, int& steps) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
                steps++; // Increment steps counter
            }
        }
    }
    return C;
}

// Function to divide a matrix into four submatrices
void splitMatrix(const vector<vector<int>>& A, vector<vector<int>>& A11, vector<vector<int>>& A12,
                 vector<vector<int>>& A21, vector<vector<int>>& A22) {
    int n = A.size();
    int m = n / 2;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + m];
            A21[i][j] = A[i + m][j];
            A22[i][j] = A[i + m][j + m];
        }
    }
}

// Function to merge four submatrices into one matrix
void mergeMatrix(vector<vector<int>>& C, const vector<vector<int>>& C11, const vector<vector<int>>& C12,
                 const vector<vector<int>>& C21, const vector<vector<int>>& C22) {
    int n = C.size();
    int m = n / 2;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + m] = C12[i][j];
            C[i + m][j] = C21[i][j];
            C[i + m][j + m] = C22[i][j];
        }
    }
}

// Function to add two matrices recursively
vector<vector<int>> matrixAdditionRecursive(const vector<vector<int>>& A, const vector<vector<int>>& B, int& steps) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    if (n == 1) {
        C[0][0] = A[0][0] + B[0][0];
        // steps++; // Increment steps counter
    } else {
        vector<vector<int>> A11(n / 2, vector<int>(n / 2));
        vector<vector<int>> A12(n / 2, vector<int>(n / 2));
        vector<vector<int>> A21(n / 2, vector<int>(n / 2));
        vector<vector<int>> A22(n / 2, vector<int>(n / 2));
        vector<vector<int>> B11(n / 2, vector<int>(n / 2));
        vector<vector<int>> B12(n / 2, vector<int>(n / 2));
        vector<vector<int>> B21(n / 2, vector<int>(n / 2));
        vector<vector<int>> B22(n / 2, vector<int>(n / 2));
        vector<vector<int>> C11(n / 2, vector<int>(n / 2));
        vector<vector<int>> C12(n / 2, vector<int>(n / 2));
        vector<vector<int>> C21(n / 2, vector<int>(n / 2));
        vector<vector<int>> C22(n / 2, vector<int>(n / 2));

        splitMatrix(A, A11, A12, A21, A22);
        splitMatrix(B, B11, B12, B21, B22);

        C11 = matrixAdditionRecursive(A11, B11, steps);
        C12 = matrixAdditionRecursive(A12, B12, steps);
        C21 = matrixAdditionRecursive(A21, B21, steps);
        C22 = matrixAdditionRecursive(A22, B22, steps);

        mergeMatrix(C, C11, C12, C21, C22);
    }
    return C;
}

// Function to subtract two matrices recursively
vector<vector<int>> matrixSubtractionRecursive(const vector<vector<int>>& A, const vector<vector<int>>& B, int& steps) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    if (n == 1) {
        C[0][0] = A[0][0] - B[0][0];
        // steps++; // Increment steps counter
    } else {
        vector<vector<int>> A11(n / 2, vector<int>(n / 2));
        vector<vector<int>> A12(n / 2, vector<int>(n / 2));
        vector<vector<int>> A21(n / 2, vector<int>(n / 2));
        vector<vector<int>> A22(n / 2, vector<int>(n / 2));
        vector<vector<int>> B11(n / 2, vector<int>(n / 2));
        vector<vector<int>> B12(n / 2, vector<int>(n / 2));
        vector<vector<int>> B21(n / 2, vector<int>(n / 2));
        vector<vector<int>> B22(n / 2, vector<int>(n / 2));
        vector<vector<int>> C11(n / 2, vector<int>(n / 2));
        vector<vector<int>> C12(n / 2, vector<int>(n / 2));
        vector<vector<int>> C21(n / 2, vector<int>(n / 2));
        vector<vector<int>> C22(n / 2, vector<int>(n / 2));

        splitMatrix(A, A11, A12, A21, A22);
        splitMatrix(B, B11, B12, B21, B22);

        C11 = matrixSubtractionRecursive(A11, B11, steps);
        C12 = matrixSubtractionRecursive(A12, B12, steps);
        C21 = matrixSubtractionRecursive(A21, B21, steps);
        C22 = matrixSubtractionRecursive(A22, B22, steps);

        mergeMatrix(C, C11, C12, C21, C22);
    }
    return C;
}

// Function to multiply two matrices using Strassen's algorithm
vector<vector<int>> strassenMatrixMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B, int& steps) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        steps++; // Increment steps counter
    } else {
        vector<vector<int>> A11(n / 2, vector<int>(n / 2));
        vector<vector<int>> A12(n / 2, vector<int>(n / 2));
        vector<vector<int>> A21(n / 2, vector<int>(n / 2));
        vector<vector<int>> A22(n / 2, vector<int>(n / 2));
        vector<vector<int>> B11(n / 2, vector<int>(n / 2));
        vector<vector<int>> B12(n / 2, vector<int>(n / 2));
        vector<vector<int>> B21(n / 2, vector<int>(n / 2));
        vector<vector<int>> B22(n / 2, vector<int>(n / 2));
        vector<vector<int>> P1(n / 2, vector<int>(n / 2));
        vector<vector<int>> P2(n / 2, vector<int>(n / 2));
        vector<vector<int>> P3(n / 2, vector<int>(n / 2));
        vector<vector<int>> P4(n / 2, vector<int>(n / 2));
        vector<vector<int>> P5(n / 2, vector<int>(n / 2));
        vector<vector<int>> P6(n / 2, vector<int>(n / 2));
        vector<vector<int>> P7(n / 2, vector<int>(n / 2));
        vector<vector<int>> C11(n / 2, vector<int>(n / 2));
        vector<vector<int>> C12(n / 2, vector<int>(n / 2));
        vector<vector<int>> C21(n / 2, vector<int>(n / 2));
        vector<vector<int>> C22(n / 2, vector<int>(n / 2));

        splitMatrix(A, A11, A12, A21, A22);
        splitMatrix(B, B11, B12, B21, B22);

        // Compute the seven products P1, P2, ..., P7
        P1 = strassenMatrixMultiplication(matrixAdditionRecursive(A11, A22, steps), matrixAdditionRecursive(B11, B22, steps), steps);
        P2 = strassenMatrixMultiplication(matrixAdditionRecursive(A21, A22, steps), B11, steps);
        P3 = strassenMatrixMultiplication(A11, matrixSubtractionRecursive(B12, B22, steps), steps);
        P4 = strassenMatrixMultiplication(A22, matrixSubtractionRecursive(B21, B11, steps), steps);
        P5 = strassenMatrixMultiplication(matrixAdditionRecursive(A11, A12, steps), B22, steps);
        P6 = strassenMatrixMultiplication(matrixSubtractionRecursive(A21, A11, steps), matrixAdditionRecursive(B11, B12, steps), steps);
        P7 = strassenMatrixMultiplication(matrixSubtractionRecursive(A12, A22, steps), matrixAdditionRecursive(B21, B22, steps), steps);

        // Compute the result submatrices
        C11 = matrixAdditionRecursive(matrixSubtractionRecursive(matrixAdditionRecursive(P1, P4, steps), P5, steps), P7, steps);
        C12 = matrixAdditionRecursive(P3, P5, steps);
        C21 = matrixAdditionRecursive(P2, P4, steps);
        C22 = matrixAdditionRecursive(matrixSubtractionRecursive(matrixAdditionRecursive(P1, P3, steps), P2, steps), P6, steps);

        // Merge the result submatrices into one matrix
        mergeMatrix(C, C11, C12, C21, C22);
    }
    return C;
}

int main() {
    // Example matrices
    // vector<vector<int>> A = {{1, 2}, {5, 6}};
    // vector<vector<int>> B = {{1, 0}, {0, 1}};
    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> B = {{1, 0, 0, 1}, {0, 1, 1, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}};

    // Normal Matrix Multiplication
    int normalSteps = 0;
    vector<vector<int>> C_normal = normalMatrixMultiplication(A, B, normalSteps);
    cout << "Normal Matrix Multiplication:" << endl;
    for (const auto& row : C_normal) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "Steps taken by normal multiplication: " << normalSteps << endl;

    // Strassen's Matrix Multiplication
    int strassenSteps = 0;
    vector<vector<int>> C_strassen = strassenMatrixMultiplication(A, B, strassenSteps);
    cout << "\nStrassen's Matrix Multiplication:" << endl;
    for (const auto& row : C_strassen) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "Steps taken by Strassen's multiplication: " << strassenSteps << endl;

    return 0;
}
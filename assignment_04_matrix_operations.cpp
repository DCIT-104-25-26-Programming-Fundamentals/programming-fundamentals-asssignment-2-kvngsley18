// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================



#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


const int MAX_SIZE = 10;

void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "  Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}


void printMatrix(const int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// =============================================================================
// PART A — Transpose a Matrix
// =============================================================================
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int dest[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            dest[j][i] = src[i][j]; // Swap row and column indices
        }
    }
}

// =============================================================================
// PART B — Add Two Matrices
// =============================================================================
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// =============================================================================
// PART C — Multiply Two Matrices
// =============================================================================
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            result[i][j] = 0; // Initialize cell product sum
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int choice;

    cout << "=== Matrix Operations Menu ===" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter choice (1-3): ";
    cin >> choice;

    cout << endl;

    if (choice == 1) {
        int rows, cols;
        int mat[MAX_SIZE][MAX_SIZE];
        int transposed[MAX_SIZE][MAX_SIZE];

        cout << "--- Part A: Transpose Matrix ---" << endl;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(mat, rows, cols);

        transposeMatrix(mat, transposed, rows, cols);

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(mat, rows, cols);

        cout << "\nTransposed Matrix:" << endl;
        printMatrix(transposed, cols, rows); // Dimensions swap for transposed matrix

    } else if (choice == 2) {
        // Part B Demonstration
        int rows, cols;
        int A[MAX_SIZE][MAX_SIZE];
        int B[MAX_SIZE][MAX_SIZE];
        int sum[MAX_SIZE][MAX_SIZE];

        cout << "--- Part B: Add Two Matrices ---" << endl;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nEnter Matrix A:" << endl;
        readMatrix(A, rows, cols);

        cout << "\nEnter Matrix B:" << endl;
        readMatrix(B, rows, cols);

        addMatrices(A, B, sum, rows, cols);

        cout << "\nResult (A + B):" << endl;
        printMatrix(sum, rows, cols);

    } else if (choice == 3) {
        // Part C Demonstration
        int m, n, p;
        int A[MAX_SIZE][MAX_SIZE];
        int B[MAX_SIZE][MAX_SIZE];
        int product[MAX_SIZE][MAX_SIZE];

        cout << "--- Part C: Multiply Two Matrices ---" << endl;
        cout << "Enter rows for Matrix A (M): ";
        cin >> m;
        cout << "Enter columns for Matrix A / rows for Matrix B (N): ";
        cin >> n;
        cout << "Enter columns for Matrix B (P): ";
        cin >> p;

        cout << "\nEnter Matrix A (" << m << "x" << n << "):" << endl;
        readMatrix(A, m, n);

        cout << "\nEnter Matrix B (" << n << "x" << p << "):" << endl;
        readMatrix(B, n, p);

        multiplyMatrices(A, B, product, m, n, p);

        cout << "\nResult (A x B):" << endl;
        printMatrix(product, m, p);

    } else {
        cout << "Invalid choice program exit." << endl;
    }

    return 0;
}
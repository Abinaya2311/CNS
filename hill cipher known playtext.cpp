#include <stdio.h>

// Function to perform matrix multiplication
void multiplyMatrices(int matrix1[2][2], int matrix2[2][2], int result[2][2]) {
    int i, j, k;
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            result[i][j] = 0;
            for (k = 0; k < 2; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to find the inverse of a matrix mod 26
void findInverseMatrix(int matrix[2][2], int inverse[2][2]) {
    int det = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % 26;
    int invDet = 0;
    for (int i = 0; i < 26; ++i) {
        if ((det * i) % 26 == 1) {
            invDet = i;
            break;
        }
    }
    inverse[0][0] = (matrix[1][1] * invDet) % 26;
    inverse[0][1] = (-matrix[0][1] * invDet) % 26;
    inverse[1][0] = (-matrix[1][0] * invDet) % 26;
    inverse[1][1] = (matrix[0][0] * invDet) % 26;
    if (inverse[0][1] < 0) inverse[0][1] += 26;
    if (inverse[1][0] < 0) inverse[1][0] += 26;
}

int main() {
    int knownPlaintext[2][2] = {{8, 5}, {14, 22}}; // "he" -> (7, 4), "no" -> (13, 14)
    int knownCiphertext[2][2] = {{19, 5}, {18, 20}}; // "tw" -> (19, 22), "ls" -> (11, 18)

    int plaintextInverse[2][2];
    findInverseMatrix(knownPlaintext, plaintextInverse);

    int key[2][2];
    multiplyMatrices(knownCiphertext, plaintextInverse, key);

    printf("Recovered key matrix:\n");
    printf("%d %d\n", key[0][0], key[0][1]);
    printf("%d %d\n", key[1][0], key[1][1]);

    return 0;
}


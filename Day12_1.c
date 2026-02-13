#include <stdio.h>

int main() {
    int n;
    int matrix[10][10];
    int isSymmetric = 1;

    // Read size of square matrix
    printf("Enter order of matrix: ");
    scanf("%d", &n);

    // Read matrix elements
    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check symmetry
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
    }

    // Output result
    if (isSymmetric)
        printf("The matrix is symmetric\n");
    else
        printf("The matrix is not symmetric\n");

    return 0;
}
#include <stdio.h>

int main() {
    int n;
    int matrix[10][10];
    int isSymmetric = 1;

    // Read size of square matrix
    printf("Enter order of matrix: ");
    scanf("%d", &n);

    // Read matrix elements
    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check symmetry
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
    }

    // Output result
    if (isSymmetric)
        printf("The matrix is symmetric\n");
    else
        printf("The matrix is not symmetric\n");

    return 0;
}

#include <stdio.h>

void spiralTraversal(int matrix[][100], int rows, int cols)
{
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right)
    {
        // Traverse top row (left → right)
        for (int j = left; j <= right; j++)
            printf("%d ", matrix[top][j]);
        top++;

        // Traverse right column (top → bottom)
        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        // Traverse bottom row (right → left)
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
                printf("%d ", matrix[bottom][j]);
            bottom--;
        }

        // Traverse left column (bottom → top)
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }
}

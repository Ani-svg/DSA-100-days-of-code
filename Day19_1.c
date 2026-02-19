#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findClosestToZero(int arr[], int n) {
    if (n < 2) {
        printf("Need at least two elements.\n");
        return;
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int min_sum = INT_MAX;
    int min_left = left, min_right = right;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            min_left = left;
            min_right = right;
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("Two elements whose sum is closest to zero: %d and %d\n",
           arr[min_left], arr[min_right]);
    printf("Sum = %d\n", min_sum);
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findClosestToZero(arr, n);

    return 0;
}

#include <stdio.h>

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n == 0)
        return 0;

    int j = 0;  // index for unique elements

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    // Print unique elements
    for (int i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

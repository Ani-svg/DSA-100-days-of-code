#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateRight(int arr[], int n, int k) {
    k = k % n;   // Handle k > n
    
    // Step 1: Reverse entire array
    reverse(arr, 0, n - 1);
    
    // Step 2: Reverse first k elements
    reverse(arr, 0, k - 1);
    
    // Step 3: Reverse remaining elements
    reverse(arr, k, n - 1);
}

int main() {
    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    rotateRight(arr, n, k);

    printf("Array after rotation:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

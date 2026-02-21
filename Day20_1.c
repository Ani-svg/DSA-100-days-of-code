#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Simple hash map using array (works if prefix sum range is limited)
int countZeroSumSubarrays(int arr[], int n) {
    
    int prefix_sum = 0;
    int count = 0;

    // Allocate large hash array
    int hash[2 * MAX + 1] = {0};

    // To handle negative prefix sums
    int offset = MAX;

    hash[offset] = 1;  // prefix_sum = 0 initially

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if (hash[prefix_sum + offset] > 0) {
            count += hash[prefix_sum + offset];
        }

        hash[prefix_sum + offset]++;
    }

    return count;
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

    int result = countZeroSumSubarrays(arr, n);

    printf("Number of subarrays with sum 0: %d\n", result);

    return 0;
}

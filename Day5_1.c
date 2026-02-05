#include <stdio.h>

int main() {
    int n, m;

    printf("Enter size of first log: ");
    scanf("%d", &n);
    int log1[n];

    printf("Enter elements of first log:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &log1[i]);
    }

    printf("Enter size of second log: ");
    scanf("%d", &m);
    int log2[m];

    printf("Enter elements of second log:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &log2[i]);
    }

    int merged[n + m];
    int i = 0, j = 0, k = 0;

    // Merge both logs
    while (i < n && j < m) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }

    // Copy remaining elements
    while (i < n) {
        merged[k++] = log1[i++];
    }
    while (j < m) {
        merged[k++] = log2[j++];
    }

    printf("Merged chronological log:\n");
    for (int x = 0; x < n + m; x++) {
        printf("%d ", merged[x]);
    }

    return 0;
}

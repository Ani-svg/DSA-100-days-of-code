#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int left, right;
    char temp;

    // Read string
    scanf("%s", str);

    left = 0;
    right = strlen(str) - 1;

    // Reverse the string
    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }

    // Print reversed string
    printf("%s", str);

    return 0;
}

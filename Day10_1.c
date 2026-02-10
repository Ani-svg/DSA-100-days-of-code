#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, flag = 1;

    // Read the string
    printf("Enter a string: ");
    scanf("%s", str);   // reads a single word (no spaces)

    i = 0;
    j = strlen(str) - 1;

    // Two-pointer comparison
    while (i < j) {
        if (str[i] != str[j]) {
            flag = 0;
            break;
        }
        i++;
        j--;
    }

    if (flag)
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");

    return 0;
}

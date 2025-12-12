#include <stdio.h>

int main() {
    char names[30][30];  // array to hold up to 30 names, each up to 29 characters
    int n;

    printf("Enter the number of people: ");
    scanf("%d", &n);

    printf("Enter the names of %d person(s):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);  // reads one word per name
    }

    printf("\nNames entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
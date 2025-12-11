#include <stdio.h>
int main() {
    char food1[] = "Pizza";
    char food2[] = "Burger";
    char food3[] = "Pasta";

    int price1, price2, price3;

    printf("Menu:\n%s\n%s\n%s\n", food1, food2, food3);
    printf("Enter the prices of %s, %s and %s:\n", food1, food2, food3);
    scanf("%d %d %d", &price1, &price2, &price3);

    printf("You ordered:\n");
    printf("%s - %d\n", food1, price1);
    printf("%s - %d\n", food2, price2);
    printf("%s - %d\n", food3, price3);

    int total = price1 + price2 + price3;
    printf("Total = %d\n", total);

    return 0;
}
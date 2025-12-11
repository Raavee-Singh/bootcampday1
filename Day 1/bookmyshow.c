#include<stdio.h>
int main()
{
    char name[50];
    char email[50];
    int number;
    printf("Movie Billing Program\n");
    printf("Movie Ticket Price: 100Rs.");
    printf("Enter the customer name:\n");
    scanf("%s", &name);
    printf("Enter the email id:\n");
    scanf("%s", &email);
    printf("Enter the number of seats:\n");
    scanf("%d", &number);

    if (number<2) {
        printf("No discount applied.\n");
    } else if(number>=2 && number<=4){
        printf("Discount of Rs.20 applied.\n");}
        else if(number>4 && number<8){
        printf("Discount of Rs.40 applied.\n");
        }
        else if(number>100){
            printf("Free ticket!\n");

    }

    return 0;
}
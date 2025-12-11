#include<stdio.h>
int main()
{
    int num;
    do{
        printf("Enter a number (enter 5 to stop):");
        scanf("%d",&num);
    }while(num!=5);
    printf("You entered 5, exiting the loop.\n");
    return 0;
    
}
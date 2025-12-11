#include<stdio.h>
int main()
{
    int number;
    while(number!=99)
    {
    printf("----Menu----\n");
    printf("Menu Choice\n");
    printf("1. Order Food\n");
    printf("2. Refund Status\n");
    printf("3. Check previous Orders\n");
    printf("Enter choice:\n");
    scanf("%d", &number);
    if(number==1)
        printf("Display Menu items.\n");
    else if(number==2)
        printf("Refund creditted.\n");
    else if(number==3)
        printf("No previous orders!\n");       
break;
    }
    
    return 0;
}
#include<stdio.h>
int main() {
    float a, b;
    char op;
    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);      

    switch(op) {
        case '+':
            printf("Sum=%.2f\n",a + b);
            break;
        case '-':
            printf("Diff=%.2f\n",a - b);
            break;
        case '*':
            printf("Product=%.2f\n",a * b);
            break;
        case '/':
            if(b!=0)
                printf("Division=%.2f\n",a / b);
            else
                printf("Error!\n");
            break;
        default:
            printf("Error: Invalid operator.\n");
    }
   
    return 0;
}
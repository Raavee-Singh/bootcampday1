#include<stdio.h>
#include<ctype.h>
void keyA()
{
    printf("A is pressed\n");
}

void keyB()
{
    printf("B is pressed\n");
}

void keyC()
{
    printf("C is pressed\n");
}

void keyD()
{
    printf("D is pressed\n");
}

int main()
{
    char ch;
    printf("Press a key (A, B, C, D): ");
    scanf(" %c", &ch);
    ch = toupper(ch); // Convert to uppercase to handle lowercase input

    switch(ch)
    {
        case 'A':
            keyA();
            break;
        case 'B':
            keyB();
            break;
        case 'C':
            keyC();
            break;
        case 'D':
            keyD();
            break;
        default:
            printf("Invalid key pressed!\n");
    }

    return 0;
}
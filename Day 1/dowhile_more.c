#include<stdio.h>
int main()
{
    int num=0;
    while(num<5){
        printf("I am smart. You are dumb.\n");
        num=num+1;
    }
    do{
        printf("I am smart. You are dumb.\n");
        num=num+1;
    }while(num<5);
    return 0;
}
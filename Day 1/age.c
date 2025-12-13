#include<stdio.h>
int main()
{
int age=29;
if(age<8)
    printf("Baby");
else if(age>=8 && age<20)
    printf("Teen");
else if(age>20 && age<30)
    printf("Uncle/aunty start phase");
else if(age>30 && age<50)
    printf("Grandpaa/Granny level unlocked ");
    return 0;
}
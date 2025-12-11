#include<stdio.h>
int main()
{
    int subject1, subject2, subject3, subject4, subject5, subject6;
    printf("Enter marks in subject 1:");
    scanf("%d",&subject1);
    printf("Enter marks in subject 2:");
    scanf("%d",&subject2);
    printf("Enter marks in subject 3: ");
    scanf("%d",&subject3);
    printf("Enter marks in subject 4: ");
    scanf("%d",&subject4);
    printf("Enter marks in subject 5: ");
    scanf("%d",&subject5);
    printf("Enter marks in subject 6: ");
    scanf("%d",&subject6);

    float total=(subject1 + subject2 + subject3 + subject4 + subject5 + subject6)/6.0;
    return 0;
}
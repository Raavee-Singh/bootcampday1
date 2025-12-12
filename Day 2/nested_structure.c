#include<stdio.h>
#include<string.h>
struct date
{
    int day;
    int month;
    int year;
};  
struct student
{
    char name[50];
    struct date dob;
};
int main()
{
    struct student s1={"Alice", {14,8,2007}};
    printf("Name: %s\n", s1.name);
    printf("Date of Birth: %02d-%02d-%04d\n", s1.dob.day, s1.dob.month, s1.dob.year);
    return 0;
}
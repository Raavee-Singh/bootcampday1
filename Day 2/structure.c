#include<stdio.h>
#include<string.h>

struct student {
    char name[50];
    int age;
    float marks;
};

int main() {
    struct student s1;

    strcpy(s1.name, "Alice");
    s1.age = 20;
    s1.marks = 85.5;

    printf("Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("Marks: %.2f\n", s1.marks);

    return 0;
}
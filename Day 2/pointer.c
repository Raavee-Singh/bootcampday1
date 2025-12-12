/*
#include<stdio.h>
int main() {
    int a=10;
    int *p=&a;
    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", &a);
    printf("Pointer p points to address: %p\n", p);
    printf("Value of pointer p: %d\n", *p);
    printf("Address of pointer p: %p\n", &p);
    return 0;
} */
#include<stdio.h>
int main() {
    int weight=10;
    int *house_address=&weight;
    printf("Weight of parcel: %d kg\n", weight);
    printf("Address for delivery: %p\n", &weight);
    printf("accessing pointer using weight: %d\n", *house_address);

    return 0;
}
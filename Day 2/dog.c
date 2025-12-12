#include <stdio.h>
#include <string.h>

struct Dog {
    char name[50];
    char breed[25];
    int age;
    char nationality[25];
};

int main() {
    struct Dog d;

    // Assign values with validation
    strcpy(d.name, "Tommy");
    strcpy(d.breed, "Golden Retriever");
    d.age = 5;
    strcpy(d.nationality, "USA");

    // Display the dog's details
    printf("Dog Details:\n");
    printf("Name: %s\n", d.name);
    printf("Breed: %s\n", d.breed);
    printf("Age: %d\n", d.age);
    printf("Nationality: %s\n", d.nationality);

    return 0;
}
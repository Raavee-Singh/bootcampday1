#include<stdio.h>
int main() {
    int arr[5];
    printf("Enter the elements of the array: ");
    for(int i=0;i<5;i++)
    scanf("%d", &arr[i]);

    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }   
    printf("\n");

    return 0;
}
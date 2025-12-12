#include<stdio.h>
int main() {
    int arr[5]={10,20,30,40,50};
    int search, found=0;
    printf("Enter element to search: ");
    scanf("%d", &search);
    for(int i=0;i<5;i++){
        if(arr[i]==search){
            found=1;
            break;
        }
    }

    if(found)
        printf("Element found\n");
    else
        printf("Element not found\n");  
    return 0;
}
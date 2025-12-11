#include<stdio.h>
#include<stdlib.h>
int main() {
   int n, i, key, mid, low, high, a[30];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the array elements in ascending order:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }   
    printf("Enter the element to be searched: ");
    scanf("%d", &key); 
    low = 0;
    high = n - 1;
    while(low <= high) {    
        mid = (low + high) / 2;
        if(a[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            exit(0);
        }
        else if(a[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }   
    return 0;
}
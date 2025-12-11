#include<stdio.h>
#include<stdlib.h>
int main() {
int i, j, n, temp, scores[100];
printf("Enter number of elements: ");
scanf("%d", &n);    
printf("Enter the scores:\n");
for(i = 0; i < n; i++) {
    scanf("%d", &scores[i]);    
}
for(i = 0; i < n - 1; i++) {        
    for(j = 0; j < n - i - 1; j++) {
        if(scores[j] < scores[j + 1]) {
            temp = scores[j];
            scores[j] = scores[j + 1];
            scores[j + 1] = temp;
        }
    }
}
printf("Scores in descending order:\n");
for(i = 0; i < n; i++) {
    printf("%d\n", scores[i]);      
}   
    return 0;
}
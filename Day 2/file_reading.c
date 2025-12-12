#include<stdio.h>
int main() {
    FILE *fp;
    char line[200];
    fp = fopen("C.txt", "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    while(fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);

    return 0;
}


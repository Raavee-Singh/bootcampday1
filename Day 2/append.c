#include<stdio.h>
int main() {
    FILE *fp;
    char line[200];
    fp = fopen("C.txt", "a");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    fprintf(fp, "I live in Mysore!\n");
    fprintf(fp, "I love Mysore!\n");
    fprintf(fp, "I enjoy coding in C!\n");
    fclose(fp);

    return 0;
}
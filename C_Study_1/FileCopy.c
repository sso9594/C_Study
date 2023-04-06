#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    FILE* fp1;
    FILE* fp2;
    char c;

    fp1 = fopen("a.txt", "r");
    fp2 = fopen("b.txt", "w");

    while ((c = fgetc(fp1)) != EOF) {
        fputc(c, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    fp2 = fopen("b.txt", "r");

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp2) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp2);

    return 0;
}
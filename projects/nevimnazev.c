#include <stdio.h>

#define FILENAME "cisla.txt"

void listEnter(FILE *fw) {
    fprintf(fw, "\n");
}

int main(void) {
    FILE *file;
    int symbol;
    
    int base;
    int exponent;

    file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("Soubor %s se nepodarilo otevrit.\n", FILENAME);
        return 1;
    }

    while (fscanf(file, "%d%d", &base, &exponent) != EOF) {
        printf("%d^%d\n", base, exponent);
    }

    if (fclose(file) != 0) {
        printf("Chyba pri zavirani souboru %s.\n", FILENAME);
        return 1;
    }

    listEnter(stdout);
    printf("Soubor byl uspesne uzavren.\n");

    return 0;
}

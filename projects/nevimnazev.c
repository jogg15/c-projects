#include <stdio.h>

#define FILENAME "cisla.txt"
#define RESULTFILE "vysledky.txt"

unsigned int powers(const int base, int exponent) {
    unsigned int result = 1;
    for (; exponent >  0; exponent--) {
        result *= base;
    }
    return result;
}

void listEnter(FILE *fw) {
    fprintf(fw, "\n");
}

void listResult(FILE *fw, const int base, const int exponent) {
    fprintf(fw, "%d^%d = %d\n", base, exponent, powers(base, exponent));
}

int fileClose (FILE *fw, const char *filename) {
    if (fclose(fw) != 0) {
        printf("Chyba pri zavirani souboru %s.\n", filename);
    }
    return 0;
}

int main(void) {
    int base;
    int exponent;

    FILE *file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("Soubor %s se nepodarilo otevrit.\n", FILENAME);
        return 1;
    }

    FILE *resultFile = fopen(RESULTFILE, "w");

    if (resultFile == NULL) {
        printf("Nepodarilo se nacist soubor %s.\n", RESULTFILE);
    } else {
        printf("Uspesne se nacetl soubor %s.\n", RESULTFILE);
    }

    while (fscanf(file, "%d%d", &base, &exponent) != EOF) {
        listResult(stdout, base, exponent);
        listResult(resultFile, base, exponent);
    }

    fileClose(file, RESULTFILE);

    listEnter(stdout);
    printf("Soubor byl uspesne uzavren.\n");

    return 0;
}

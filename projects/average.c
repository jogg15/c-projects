#include <stdio.h>

int main () {
    int num, sum = 0;

    printf("Zadej pocet cisel: ");
    scanf(" %d", &num);
    for (int i = 0; i < num; i++) {
        int num;
        printf("Zadej cislo %d: ", i + 1);
        scanf(" %d", &num);
        sum += num;
    }
    const float average = (float) sum / num;
    printf("Prumer je: %.2f\n", average);
    return 0;
}
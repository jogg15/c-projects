#include <stdio.h>

int main() {
    float height, weight;

    printf("Zadej svoji vysku v metrech: ");
    scanf(" %f", &height);

    printf("Zadej svoji vahu v kg: ");
    scanf(" %f", &weight);

    const float result = weight / (height * height);

    printf("Tve BMI je: %f\n", result);

    return 0;
}

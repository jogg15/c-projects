#include <stdio.h>
#include <stdlib.h>

#define INPUT "cisla.txt"
#define OUTPUT "output.txt"
#define ARRAY_SIZE 30

typedef struct {
    int meters;
    int seconds;
} DISTANCE;

int fileRead(DISTANCE *array) {
    int index = 0;

    FILE *fr = fopen(INPUT, "r");
    if (fr == NULL) {
        printf("Error opening input file\n");
        return -1;
    }

    while (index < ARRAY_SIZE &&
           fscanf(fr, "%d%d",
                  &array[index].meters,
                  &array[index].seconds) == 2) {
        index++;
    }

    fclose(fr);
    return index;
}

void header() {
    printf("order    distance     time   speed\n");
    printf("----------------------------------\n");
}

float speedCalc(const DISTANCE distance) {
    if (distance.seconds == 0) {
        return 0.0f;
    }

    return (float)distance.meters / distance.seconds;
}

void printout(const DISTANCE *distance, const int distanceCount) {
    header();

    for (int i = 0; i < distanceCount; i++) {
        printf("%2d. %13d %8d %7.2f\n",
               i + 1,
               distance[i].meters,
               distance[i].seconds,
               speedCalc(distance[i]));
    }
}

void bubbleSort(DISTANCE arr[], const int pairCount) {
    for (int i = 0; i < pairCount - 1; i++) {
        for (int j = 0; j < pairCount - i - 1; j++) {

            if (speedCalc(arr[j]) < speedCalc(arr[j + 1])) {

                DISTANCE tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void outputting(DISTANCE arr[], const int pairCount) {

    FILE *fw = fopen(OUTPUT, "w");

    if (fw == NULL) {
        printf("Error opening output file\n");
        return;
    }

    fprintf(fw, "Entries with speed over 10 m/s\n");
    fprintf(fw, "--------------------------------\n");

    for (int i = 0; i < pairCount; i++) {

        if (speedCalc(arr[i]) > 10.0f) {

            fprintf(fw,
                    "%2d. distance=%d time=%d speed=%.2f\n",
                    i + 1,
                    arr[i].meters,
                    arr[i].seconds,
                    speedCalc(arr[i]));
        }
    }

    fclose(fw);
}

int main(void) {

    DISTANCE distance[ARRAY_SIZE];

    int pairCount = fileRead(distance);

    if (pairCount <= 0) {
        return EXIT_FAILURE;
    }

    bubbleSort(distance, pairCount);

    printout(distance, pairCount);

    outputting(distance, pairCount);

    return 0;
}

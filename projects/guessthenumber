#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNumberGen(void) {
    return rand() % 101;
}

int main (void) {
    srand(time(NULL)); 
    int secretNumber = randomNumberGen();
    int cislo;
    int tries = 10;
    
    printf("Uhodni nahodne cislo [0-100]:\n");
    
    while (tries > 0) {
        printf("Zbyvajici pokusy: %d\n", tries);
        scanf("%d", &cislo);

        if (cislo == secretNumber) {
            printf("Uhodl jsi cislo!\n");
            break;
        } else if (cislo < secretNumber) {
            printf("Cislo je vetsí!\n");
        } else {
            printf("Cislo je mensí!\n");
        }
        tries--;
    }
    
    if (tries == 0) {
        printf("Vyprsely pokusy! Spravne cislo bylo: %d\n", secretNumber);
    }
    
    return 0;
}

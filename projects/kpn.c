#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int kpn(char const user, char const comp) {
    if (user == comp) return -1;

    return (user == 'k' && comp == 'n') ||
           (user == 'p' && comp == 'k') ||
           (user == 'n' && comp == 'p');
}

int main() {
    char user, comp;

    srand(time(NULL));

    const int random = rand() % 3;
    if (random == 0) comp = 'k';
    else if (random == 1) comp = 'p';
    else comp = 'n';

    printf("k = Kamen; p = Papir, n = Nuzky: ");
    scanf(" %c", &user);

    if (user != 'k' && user != 'p' && user != 'n') {
        printf("Neplatna volba!\n");
        return 1;
    }

    const int result = kpn(user, comp);

    if (result == -1)
        printf("Remiza!\n");
    else if (result == 1)
        printf("Vyhral jsi!\n==========\n");
    else
        printf("Prohral jsi. Zkus to znova!\n");

    printf("Ty: %c\nPocitac: %c\n", user, comp);
    return 0;
}

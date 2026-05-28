#include <stdio.h>
#include <string.h>

int mechanism(int position, int shift) {
    position = (position + shift) % 26;
    if (position < 0) position += 26;
    return position;
}

void cipher(char *text, int shift, const int mode) {
    if (mode == 1) {
        shift = -shift;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        // male pismena
        if (c >= 'a' && c <= 'z') {
            int position = c - 'a';
            position = mechanism(position, shift);
            text[i] = 'a' + position;
        }

        // velke pismena
        else if (c >= 'A' && c <= 'Z') {
            int position = c - 'A';
            position = mechanism(position, shift);
            text[i] = 'A' + position;
        }
    }
}

int main() {
    char text[1000];
    int shift;
    int mode;

    printf("0 - Cipher\n");
    printf("1 - Decipher\n");
    printf("Choose an operation: ");
    scanf("%d", &mode);

    printf("Enter text to cipher:\n");
    getchar(); // newline
    fgets(text, sizeof(text), stdin);

    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    printf("Enter the offset (integer):\n");
    scanf("%d", &shift);

    shift = shift % 26;
    cipher(text, shift, mode);

    printf("Result: ");
    if (mode == 0) {
        printf("Ciphered text: %s\n", text);
    } else {
        printf("Deciphered text: %s\n", text);
    }

    return 0;
}

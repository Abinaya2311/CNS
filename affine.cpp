#include <stdio.h>
#include <ctype.h>
#include<string.h>

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; ++x) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

void affineCipher(char *text, int a, int b, int encrypt) {
    int i;
    for (i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            char offset = isupper(text[i]) ? 'A' : 'a';
            if (encrypt) {
                text[i] = ((a * (text[i] - offset) + b) % 26) + offset;
            } else {
                int a_inv = modInverse(a, 26);
                text[i] = (a_inv * ((text[i] - offset - b + 26) % 26)) % 26 + offset;
            }
        }
    }
}

int main() {
    char text[100];
    int a, b, choice;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 

    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    printf("Enter 1 to encrypt or 0 to decrypt: ");
    scanf("%d", &choice);

    affineCipher(text, a, b, choice);

    printf("%s text: %s\n", choice ? "Encrypted" : "Decrypted", text);

    return 0;
}


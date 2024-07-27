#include <stdio.h>
#include <string.h>
#include<ctype.h>

void generateKey(char *key, char *alphabet) {
    int used[26] = {0};
    int index = 0;

    // Add the keyword to the alphabet
    for (int i = 0; key[i] != '\0'; i++) {
        if (!used[key[i] - 'A']) {
            alphabet[index++] = key[i];
            used[key[i] - 'A'] = 1;
        }
    }

    // Add remaining letters
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            alphabet[index++] = ch;
        }
    }
    alphabet[index] = '\0';
}

void encryptText(char *plaintext, char *key, char *ciphertext) {
	int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char ch = toupper(plaintext[i]);
            ciphertext[i] = key[ch - 'A'];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}

int main() {
    char key[] = "CIPHER";
    char alphabet[27];
    char plaintext[100] = "Hello World";
    char ciphertext[100];

    generateKey(key, alphabet);

    printf("Generated Cipher Alphabet: %s\n", alphabet);

    encryptText(plaintext, alphabet, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}


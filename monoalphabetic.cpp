#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *plaintext, char *ciphertext, char *mapping) {
    int i;
    char ch;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        ch = plaintext[i];
        
        if (isupper(ch)) {
            plaintext[i] = toupper(mapping[ch - 'A']);
        }
        else if (islower(ch)) {
            plaintext[i] = tolower(mapping[ch - 'a']);
        }
    }
}

int main() {
    char plaintext[100];
    char mapping[27] = "QWERTYUIOPASDFGHJKLZXCVBNM"; 
    char ciphertext[100];

    printf("Enter a string to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    strcpy(ciphertext, plaintext); 

    encrypt(ciphertext, ciphertext, mapping);

    printf("Encrypted string: %s\n", ciphertext);

    return 0;
}


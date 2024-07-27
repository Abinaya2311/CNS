#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenereCipher(char *text, char *key, int encrypt) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < textLen; ++i) {
        if (isalpha(text[i])) {
            char offset = isupper(text[i]) ? 'A' : 'a';
            char keyChar = tolower(key[j % keyLen]) - 'a';
            if (encrypt) {
                text[i] = (text[i] - offset + keyChar) % 26 + offset;
            } else {
                text[i] = (text[i] - offset - keyChar + 26) % 26 + offset;
            }
            ++j;
        }
    }
}

int main() {
    char text[100], key[100];
    int choice;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 

    printf("Enter 1 to encrypt or 0 to decrypt: ");
    scanf("%d", &choice);

    vigenereCipher(text, key, choice);

    printf("%s text: %s\n", choice ? "Encrypted" : "Decrypted", text);

    return 0;
}


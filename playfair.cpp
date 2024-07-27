#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void generateKeyTable(char key[], char keyTable[SIZE][SIZE]) {
    int dict[26] = {0};
    int i, j, k, flag = 0, row = 0, col = 0;

    for (i = 0; key[i] != '\0'; ++i) {
        if (key[i] != 'j' && !dict[key[i] - 'a']) {
            keyTable[row][col++] = key[i];
            dict[key[i] - 'a'] = 1;
            if (col == SIZE) {
                col = 0;
                ++row;
            }
        }
    }

    for (i = 0; i < 26; ++i) {
        if (i != 9 && !dict[i]) {
            keyTable[row][col++] = (char) (i + 'a');
            if (col == SIZE) {
                col = 0;
                ++row;
            }
        }
    }
}

void formatText(char text[]) {
    int i, j;
    for (i = 0; text[i] != '\0'; ++i) {
        if (text[i] == 'j') {
            text[i] = 'i';
        }
    }

    for (i = 0; text[i] != '\0'; i += 2) {
        if (text[i + 1] == '\0') {
            text[i + 1] = 'x';
            text[i + 2] = '\0';
        } else if (text[i] == text[i + 1]) {
            for (j = strlen(text) + 1; j > i + 1; --j) {
                text[j] = text[j - 1];
            }
            text[i + 1] = 'x';
        }
    }
}

void search(char keyTable[SIZE][SIZE], char a, char b, int pos[]) {
    int i, j;

    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (keyTable[i][j] == a) {
                pos[0] = i;
                pos[1] = j;
            } else if (keyTable[i][j] == b) {
                pos[2] = i;
                pos[3] = j;
            }
        }
    }
}

void encrypt(char text[], char keyTable[SIZE][SIZE]) {
    int i, pos[4];
    for (i = 0; text[i] != '\0'; i += 2) {
        search(keyTable, text[i], text[i + 1], pos);

        if (pos[0] == pos[2]) {
            text[i] = keyTable[pos[0]][(pos[1] + 1) % SIZE];
            text[i + 1] = keyTable[pos[2]][(pos[3] + 1) % SIZE];
        } else if (pos[1] == pos[3]) {
            text[i] = keyTable[(pos[0] + 1) % SIZE][pos[1]];
            text[i + 1] = keyTable[(pos[2] + 1) % SIZE][pos[3]];
        } else {
            text[i] = keyTable[pos[0]][pos[3]];
            text[i + 1] = keyTable[pos[2]][pos[1]];
        }
    }
}

int main() {
    char key[30], text[100], keyTable[SIZE][SIZE];

    printf("Enter the key: ");
    scanf("%s", key);
    printf("Enter the text: ");
    scanf("%s", text);

    generateKeyTable(key, keyTable);
    formatText(text);
    encrypt(text, keyTable);

    printf("Encrypted text: %s\n", text);

    return 0;
}

